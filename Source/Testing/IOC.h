#pragma once

#include "Runtime/Core/Public/Misc/TypeContainer.h"
#include "IOC.generated.h"

/**
 * UIOC provides access to the IOC container.
 */
UCLASS()
class UIOC : public UObject
{
	GENERATED_BODY()

public:

	// Container
	static TTypeContainer<> Container;
	
};