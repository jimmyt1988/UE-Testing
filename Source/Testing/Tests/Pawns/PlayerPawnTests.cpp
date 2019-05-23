#include "Common.h"
#include "Misc/AutomationTest.h"
#include "../Shared/TestExecutive.h"
#include "PlayerPawn/Enemy_doesnt_lose_life_when_player_power_modifier_is_less_than_enemy_power.h"
#include "PlayerPawn/Enemy_loses_life_when_player_power_modifier_is_equal_to_enemy_power.h"
#include "PlayerPawn/Enemy_loses_life_when_player_power_modifier_is_greater_than_enemy_power.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(PlayerPawnTests, "Pawns.PlayerPawnTests", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool PlayerPawnTests::RunTest(const FString& Parameters)
{
	TestExecutive* testExecutive = new TestExecutive(this);

	testExecutive
		->Add<Enemy_doesnt_lose_life_when_player_power_modifier_is_less_than_enemy_power>()
		->Add<Enemy_loses_life_when_player_power_modifier_is_equal_to_enemy_power>()
		->Add<Enemy_loses_life_when_player_power_modifier_is_greater_than_enemy_power>()
		->Execute();

	return true;
}