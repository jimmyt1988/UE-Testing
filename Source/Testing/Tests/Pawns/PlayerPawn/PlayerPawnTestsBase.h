#pragma once

#include "../../Shared/BaseTestAgent.h"
#include "Runtime/Core/Public/Misc/TypeContainer.h"
#include "Runtime/Core/Public/Templates/SharedPointer.h"
#include "../../../Services/Abstracts/IPlayerService.h"
#include "../../../Services/Concretes/PlayerService.h"
#include "../../../Pawns/EnemyPawn.h"
#include "../../../Pawns/PlayerPawn.h"

class PlayerPawnTestsBase : public BaseTestAgent
{
public:

	PlayerPawnTestsBase(FAutomationTestBase* AutomationTestBase);

	// Inherited via BaseTestAgent
	virtual bool RunTest() override = 0;

protected:

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
};