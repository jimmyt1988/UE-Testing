#pragma once

#include <functional>
#include "AutomationTest.h"

// Gives structure to a test
// 
// Note: If you need access to FAutomationTestBase, you can declare a constructor like so:
// YourClassName(FAutomationTestBase* automationTestBase) 
// : BaseTestAgent(automationTestBase) { ... }
class BaseTestAgent
{
public: // Methods

	// 
	BaseTestAgent(FAutomationTestBase* automationTestBase);

	// 
	virtual bool RunTest() = 0;

protected: // Methods

	// 
	virtual ~BaseTestAgent();

protected: // Properties

	// 
	FAutomationTestBase* automationTestBase;

};