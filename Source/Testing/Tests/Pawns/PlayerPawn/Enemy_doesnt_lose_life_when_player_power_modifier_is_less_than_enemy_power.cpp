#include "Enemy_doesnt_lose_life_when_player_power_modifier_is_less_than_enemy_power.h"

Enemy_doesnt_lose_life_when_player_power_modifier_is_less_than_enemy_power::Enemy_doesnt_lose_life_when_player_power_modifier_is_less_than_enemy_power(FAutomationTestBase * AutomationTestBase)
	: PlayerPawnTestsBase(AutomationTestBase)
{
}

bool Enemy_doesnt_lose_life_when_player_power_modifier_is_less_than_enemy_power::RunTest()
{
	EnemyPawn->Life = 1;
	EnemyPawn->Power = 2;

	PlayerPawn->TriggerVolumeHitOccured(PlayerPawn->CollisionComponent, EnemyPawn, EnemyPawn->CollisionComponent, FVector::ZeroVector, HitResult);

	AutomationTestBase->TestEqual("Enemy doesn't lose life when player power modifier is < than enemy power", EnemyPawn->Life, 1);

	return true;
}