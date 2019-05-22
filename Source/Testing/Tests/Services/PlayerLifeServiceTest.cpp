#include "Misc/AutomationTest.h"
#include "Runtime/Core/Public/Misc/TypeContainer.h"
#include "Runtime/Core/Public/Templates/SharedPointer.h"
#include "../../Services/Abstracts/IPlayerService.h"
#include "../../Services/Concretes/PlayerService.h"
#include "../../Pawns/EnemyPawn.h"
#include "../../Pawns/PlayerPawn.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(PlayerLifeServiceTest, "Services.PlayerLifeServiceTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

class MockPlayerLifeService : public IPlayerService
{
public:

	// Inherited via IPlayerService
	virtual int GetPowerModifier(APlayerPawn * PlayerPawn) override
	{
		return 1;
	}

};

bool PlayerLifeServiceTest::RunTest(const FString& Parameters)
{
	TTypeContainer<> Container;

	MockPlayerLifeService* MockPlayerLifeService;
	TSharedRef<IPlayerService> SharedMockPlayerLifeService = MakeShareable(MockPlayerLifeService);

	Container.RegisterInstance<IPlayerService>(SharedMockPlayerLifeService);

	APlayerPawn* PlayerPawn = NewObject<APlayerPawn>();
	AEnemyPawn* EnemyPawn = NewObject<AEnemyPawn>();
	FHitResult HitResult;

	//////////////////

	EnemyPawn->Life = 1;
	EnemyPawn->Power = 1;

	PlayerPawn->TriggerVolumeHitOccured(PlayerPawn->CollisionComponent, EnemyPawn, EnemyPawn->CollisionComponent, FVector::ZeroVector, HitResult);	

	TestEqual("Enemy did not lose life if player power modifier less than enemy power", EnemyPawn->Life, 1);

	/////////////////

	EnemyPawn->Life = 1;
	EnemyPawn->Power = 0;

	PlayerPawn->TriggerVolumeHitOccured(PlayerPawn->CollisionComponent, EnemyPawn, EnemyPawn->CollisionComponent, FVector::ZeroVector, HitResult);


	TestEqual("Enemy lost life if player power modifier more than or equal to enemy power", EnemyPawn->Life, 1);

	return true;
}