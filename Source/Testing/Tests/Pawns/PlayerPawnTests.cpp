#include "Common.h"
#include "Misc/AutomationTest.h"

#include "../../Services/Abstracts/IPlayerService.h"
#include "../../Pawns/EnemyPawn.h"
#include "../../Pawns/PlayerPawn.h"

/**
 * Serves as a container to help with code maintenance in tests. 
 * See below class for actual test entry point
 */
class PlayerPawnTestsAgent
{
private:

	FAutomationTestBase* AutomationTestBase;
	APlayerPawn* PlayerPawn;
	AEnemyPawn* EnemyPawn;
	FHitResult HitResult;

	class MockPlayerService : public IPlayerService
	{
	public:

		// Inherited via IPlayerService
		virtual int GetPowerModifier(APlayerPawn * PlayerPawn) override
		{
			return 1;
		}

	};

public:

	PlayerPawnTestsAgent(FAutomationTestBase* AutomationTestBase)
		: AutomationTestBase(AutomationTestBase)
	{
		// Create an instance of the mock player service
		TSharedRef<IPlayerService> SharedMockPlayerService = MakeShareable(new MockPlayerService());

		// Register the instance to our container
		UIOC::Container.RegisterInstance<IPlayerService>(SharedMockPlayerService);

		// Instantiate the mock objects used in the test
		PlayerPawn = NewObject<APlayerPawn>();
		EnemyPawn = NewObject<AEnemyPawn>();
	}

	bool Enemy_doesnt_lose_life_when_player_power_modifier_is_less_than_enemy_power()
	{
		EnemyPawn->Life = 1;
		EnemyPawn->Power = 2;

		PlayerPawn->TriggerVolumeHitOccured(PlayerPawn->CollisionComponent, EnemyPawn, EnemyPawn->CollisionComponent, FVector::ZeroVector, HitResult);

		AutomationTestBase->TestEqual("Enemy doesn't lose life when player power modifier is < than enemy power", EnemyPawn->Life, 1);

		return true;
	}

	bool Enemy_loses_life_when_player_power_modifier_is_equal_to_enemy_power()
	{
		EnemyPawn->Life = 1;
		EnemyPawn->Power = 1;

		PlayerPawn->TriggerVolumeHitOccured(PlayerPawn->CollisionComponent, EnemyPawn, EnemyPawn->CollisionComponent, FVector::ZeroVector, HitResult);

		AutomationTestBase->TestEqual("Enemy loses life when player power modifier is == than enemy power", EnemyPawn->Life, 0);

		return true;
	}

	bool Enemy_loses_life_when_player_power_modifier_is_greater_than_enemy_power()
	{
		EnemyPawn->Life = 1;
		EnemyPawn->Power = 0;

		PlayerPawn->TriggerVolumeHitOccured(PlayerPawn->CollisionComponent, EnemyPawn, EnemyPawn->CollisionComponent, FVector::ZeroVector, HitResult);

		AutomationTestBase->TestEqual("Enemy loses life when player power modifier is > than enemy power", EnemyPawn->Life, 0);

		return true;
	}

};

IMPLEMENT_SIMPLE_AUTOMATION_TEST(PlayerPawnTests, "Pawns.PlayerPawnTests", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

// Tests for player pawn interactions with enemy
bool PlayerPawnTests::RunTest(const FString& Parameters)
{
	// Instantiate the wrapper for the tests
	PlayerPawnTestsAgent* test = new PlayerPawnTestsAgent(this);

	// Execute the tests
	test->Enemy_doesnt_lose_life_when_player_power_modifier_is_less_than_enemy_power();
	test->Enemy_loses_life_when_player_power_modifier_is_equal_to_enemy_power();
	test->Enemy_loses_life_when_player_power_modifier_is_greater_than_enemy_power();

	return true;
}