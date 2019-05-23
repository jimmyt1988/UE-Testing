#pragma once

#include <functional>
#include <vector>
#include "Tests/Shared/BaseTestAgent.h"
#include "AutomationTest.h"

//
class TestExecutive
{
public:

	// 
	TestExecutive(FAutomationTestBase* automationTestBase);

	// Add a test to execute
	template<typename T>
	TestExecutive* Add()
	{
		T* newTestAgentToRegister = new T(this->automationTestBase);
		registeredTestAgents.push_back(newTestAgentToRegister);
		return this;
	}

	// 
	void Execute();

protected:

	// 
	FAutomationTestBase* automationTestBase;

	// 
	std::vector<BaseTestAgent*> registeredTestAgents;

};