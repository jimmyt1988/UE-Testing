# UE-Testing 

## What is this project?
- An Unreal Engine project running on 4.22

## Why was it created?
- It is an example of how to implement the inversion of control (IOC) pattern using Unreal Engine's [`TTypeContainer`](https://api.unrealengine.com/INT/API/Runtime/Core/Misc/TTypeContainer/index.html)

## What does it contain?

You might want to skip to the "How does it work" section as it's more of an overview, rather than an in detail look at everything.

|Class|Description|Note|
|--|--|--|
|[Common.h](Source/Testing/Common.h)|A header that should be included in all files concerned with access to the IOC container|You'll notice it is at the top of most, if not all, of my files. [Here is an example](https://github.com/jimmyt1988/UE-Testing/blob/49985ebbbd00fabea41edd78dd5d7d67975acfba/Source/Testing/Pawns/PlayerPawn.h#L5).|
|[`UIOC`](Source/Testing/IOC.h)|Provides global access to the `TTypeContainer`|It's a `UCLASS` to help with memory management and to allow for further development|
|[`UMainGameInstance`](Source/Testing/GameInstances/MainGameInstance.h)|It's job in this project is to register interfaces to their implementations for gameplay|The constructor runs a private method called [`SetUpIOCRegistrations`](https://github.com/jimmyt1988/UE-Testing/blob/49985ebbbd00fabea41edd78dd5d7d67975acfba/Source/Testing/GameInstances/MainGameInstance.cpp#L13-L16)|
|[`APlayerPawn`](Source/Testing/Pawns/PlayerPawn.h)|Provides an example for how we resolve instances from the IOC container|Check out the [constructor](https://github.com/jimmyt1988/UE-Testing/blob/49985ebbbd00fabea41edd78dd5d7d67975acfba/Source/Testing/Pawns/PlayerPawn.cpp#L9-L18) which uses the globally accessible `UIOC` static `Container` property to resolve a `PlayerService` by the `IPlayerService` interface. **Also**, check out the `TriggerVolumeHitOccured` delegate method that uses the service to demonstrate how our tests work |
|[`AEnemyPawn`](Source/Testing/Pawns/EnemyPawn.h)|Works with the APlayerPawn to demonstrate how a test works|Check out the [`TakeHit`](https://github.com/jimmyt1988/UE-Testing/blob/49985ebbbd00fabea41edd78dd5d7d67975acfba/Source/Testing/Pawns/EnemyPawn.cpp#L16-L20) method for what our test is actually concerned about|
|[`IPlayerService`](Source/Testing/Services/Abstracts/IPlayerService.h)|The interface which we register `PlayerService` and other implementing implementations to|Check out the [`Expose_TNameOf(IPlayerService)`](https://github.com/jimmyt1988/UE-Testing/blob/49985ebbbd00fabea41edd78dd5d7d67975acfba/Source/Testing/Services/Abstracts/IPlayerService.h#L18-L19) which is required by the `RegisterClass` which is on the `TTypeContainer`. It is used to create a simple struct that allows the internals of TTypeContainer to reference your interface by name. Check it out in the [`UnrealTypeTraits.h` file](https://github.com/EpicGames/UnrealEngine/blob/7d9919ac7bfd80b7483012eab342cb427d60e8c9/Engine/Source/Runtime/Core/Public/Templates/UnrealTypeTraits.h#L203-L211)|
|[`PlayerService`](Source/Testing/Services/Concretes/PlayerService.h)|Is an implementation of the `IPlayerService`. It's not particularly interesting in terms of what it does, but it works as an example for our testing|Check out the `UMainGameInstance`'s `SetUpIOCRegistrations` method's registration of interface to implementation.|
|[PlayerPawnTests](https://github.com/jimmyt1988/UE-Testing/blob/49985ebbbd00fabea41edd78dd5d7d67975acfba/Source/Testing/Tests/Pawns/PlayerPawnTests.cpp#L87-L101)|Runs a few tests against our above code|Check out the instantiation of `PlayerPawnTestsAgent` inside its belly. I found it useful to organise my tests in this way|
|[`PlayerPawnTestsAgent`](https://github.com/jimmyt1988/UE-Testing/blob/49985ebbbd00fabea41edd78dd5d7d67975acfba/Source/Testing/Tests/Pawns/PlayerPawnTests.cpp#L8-L85)|Simply a way of managing a set of tests. I thought it was a nice way of laying them out. I'm sure there are much better ways :). I mean, I did try, just look at this messy [commit](https://github.com/jimmyt1988/UE-Testing/blob/445aed78f83241010e0c6b60560197447258494d/Source/Testing/Tests/Shared/TestExecutive.h)|Check out the constructor where i instantiate a test specific [`MockPlayerService`](https://github.com/jimmyt1988/UE-Testing/blob/49985ebbbd00fabea41edd78dd5d7d67975acfba/Source/Testing/Tests/Pawns/PlayerPawnTests.cpp#L21-L31) that helps me with my testing. **Also** notice that I call `UIOC::Container.RegisterInstance...` which sets up my container specifically for this test. My `APawn`'s `PlayerService` instance will (for my test) now be my `MockPlayerService`. Pretty cool right!|

## How does it work?
### The Game part of it:
- The `UIOC` is declared in a Common.h file that is included in all files that need access to the IOC container.
- The `UIOC` exposes a static `TTypeContainer` that is Unreal Engine's helper class for registering interfaces (`IPlayerService`) to implementations (`PlayerService`, `MockPlayerService`).
- The `UIOC` Container is populated within the `UMainGameInstance` constructor:
```cpp
UIOC::Container.RegisterClass<IPlayerService, PlayerService>();
```
- Because the `UIOC` is globally accessible and has a static `Container` property, we access this from within our `APlayerPawn`
- Inside `APlayerPawn` 's constructor, this is run:
```cpp
// Fetch PlayerService from IOC container
PlayerService = UIOC::Container.GetInstance<IPlayerService>();
```
- Then inside the actual `APlayerPawn` method `TriggerVolumeHitOccured`, we can call the `PlayerService` property which will use the implementation which we registered in the `UMainGameInstance` constructor and resolved in the pawn's constructor.
```cpp
// Get the power modifier for player
int powerModifier = PlayerService->GetPowerModifier(this);

// For example purposes, does a simple bit of logic to demonstrate test
// Note: Should be in service, but for brevity:
if (powerModifier >= EnemyPawn->Power)
{
	// Issue damage to enemy
	EnemyPawn->TakeHit();
}
```
### The testing part of it:
- The test is quite simple and is declared inside the PlayerPawnTests.cpp:
```cpp
IMPLEMENT_SIMPLE_AUTOMATION_TEST(PlayerPawnTests, "Pawns.PlayerPawnTests", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
```
- It instantiates a little wrapper class `PlayerPawnTestsAgent` where in the constructor we do something really interesting! If you were to debug this method, you will notice that even though the Container was registered to inside the `UMainGameInstance`, it is now empty. This is because our Game code is not running the constructor of the `UMainGameInstance`. Phew, well that's helpful, because now we can register our test specific versions of the `IPlayerService`:
```cpp
// Create an instance of the mock player service
TSharedRef<IPlayerService> SharedMockPlayerService = MakeShareable(new MockPlayerService());

// Register the instance to our container
UIOC::Container.RegisterInstance<IPlayerService>(SharedMockPlayerService);
```
- Then we go ahead and run our tests, and if you debug while doing so, you'll notice that the instance inside the `APlayerPawn` is our `MockPlayerService` instead of the `PlayerService`.

## Conclusion
- IOC (Inversion of control) is helpful for testing
- It removes the dependency of an implementation, and instead concerns itself only with the interface which exposes all the operations, without any of the annoying implementation details.
- The above is important because now we can put together specific data to test against. It's easy to know that ([See test example](https://github.com/jimmyt1988/UE-Testing/blob/49985ebbbd00fabea41edd78dd5d7d67975acfba/Source/Testing/Tests/Pawns/PlayerPawnTests.cpp#L49-L59)) 1 - 1 is 0. But not so easy to know that (for example) x - 1 = 0. Note the enforced value being returned from the method:
```cpp
// Inherited via IPlayerService
virtual int GetPowerModifier(APlayerPawn * PlayerPawn) override
{
	return 1;
}
```
## Other examples
- Unreal Engine actually has documentation of this (mentioned in the TTypeContainer write up) under a cpp file. [It can be found here](https://github.com/EpicGames/UnrealEngine/blob/7d9919ac7bfd80b7483012eab342cb427d60e8c9/Engine/Source/Runtime/Core/Private/Tests/Misc/TypeContainerTest.cpp).

*author: jimmyt1988*
*23/05/2019*
