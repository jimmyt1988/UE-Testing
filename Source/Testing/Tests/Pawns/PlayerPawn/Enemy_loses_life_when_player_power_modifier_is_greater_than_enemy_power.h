#pragma once

#include "../../Shared/BaseTestAgent.h"
#include "PlayerPawnTestsBase.h"

class Enemy_loses_life_when_player_power_modifier_is_greater_than_enemy_power : public PlayerPawnTestsBase
{
public:

	Enemy_loses_life_when_player_power_modifier_is_greater_than_enemy_power(FAutomationTestBase* AutomationTestBase);

	// Inherited via BaseTestAgent
	virtual bool RunTest() override;

};