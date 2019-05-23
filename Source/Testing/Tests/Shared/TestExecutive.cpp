#include "Tests/Shared/TestExecutive.h"

TestExecutive::TestExecutive(FAutomationTestBase * automationTestBase)
{
	this->automationTestBase = automationTestBase;
}

void TestExecutive::Execute()
{
	for (BaseTestAgent* testAgent : registeredTestAgents)
	{
		testAgent->RunTest();
	}
}