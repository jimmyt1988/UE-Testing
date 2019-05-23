#include "Enemy_loses_life_when_player_power_modifier_is_greater_than_enemy_power.h"

Enemy_loses_life_when_player_power_modifier_is_greater_than_enemy_power::Enemy_loses_life_when_player_power_modifier_is_greater_than_enemy_power(FAutomationTestBase * AutomationTestBase)
	: PlayerPawnTestsBase(AutomationTestBase)
{
}

bool Enemy_loses_life_when_player_power_modifier_is_greater_than_enemy_power::RunTest()
{
	EnemyPawn->Life = 1;
	EnemyPawn->Power = 0;

	PlayerPawn->TriggerVolumeHitOccured(PlayerPawn->CollisionComponent, EnemyPawn, EnemyPawn->CollisionComponent, FVector::ZeroVector, HitResult);


	AutomationTestBase->TestEqual("Enemy loses life when player power modifier is > than enemy power", EnemyPawn->Life, 0);

	return false;
}