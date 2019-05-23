#pragma once

#include "Common.h"
#include "../../Pawns/PlayerPawn.h"

/**
 * Serves logic in relation to the player
 */
struct IPlayerService
{
public:

	// Gets the power modifier for the player
	virtual int GetPowerModifier(class APlayerPawn* PlayerPawn) = 0;

};

// Used for IOC registrations
Expose_TNameOf(IPlayerService)