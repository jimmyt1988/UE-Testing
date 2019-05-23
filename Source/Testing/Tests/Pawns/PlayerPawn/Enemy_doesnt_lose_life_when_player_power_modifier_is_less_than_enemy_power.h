#pragma once

#include "../../Shared/BaseTestAgent.h"
#include "PlayerPawnTestsBase.h"

class Enemy_doesnt_lose_life_when_player_power_modifier_is_less_than_enemy_power : public PlayerPawnTestsBase
{
public:

	Enemy_doesnt_lose_life_when_player_power_modifier_is_less_than_enemy_power(FAutomationTestBase* AutomationTestBase);

	// Inherited via BaseTestAgent
	virtual bool RunTest() override;

};