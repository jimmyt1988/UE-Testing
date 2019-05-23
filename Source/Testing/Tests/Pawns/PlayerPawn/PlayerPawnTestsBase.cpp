#include "PlayerPawnTestsBase.h"

PlayerPawnTestsBase::PlayerPawnTestsBase(FAutomationTestBase * AutomationTestBase)
	: 
	BaseTestAgent(AutomationTestBase),
	AutomationTestBase(AutomationTestBase)
{
	// Create an instance of the mock player service
	TSharedRef<IPlayerService> SharedMockPlayerService = MakeShareable(new MockPlayerService());

	// Register the instance to our container
	UIOC::Container.RegisterInstance<IPlayerService>(SharedMockPlayerService);

	// Instantiate the mock objects used in the test
	PlayerPawn = NewObject<APlayerPawn>();
	EnemyPawn = NewObject<AEnemyPawn>();
}