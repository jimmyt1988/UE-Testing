#pragma once

#include "Common.h"
#include "../Abstracts/IPlayerService.h"
#include "../../Pawns/PlayerPawn.h"

/**
 * Serves logic in relation to the player
 */
class PlayerService : public IPlayerService
{
	// Inherited via IPlayerService
	// Gets the power modifier for the player
	virtual int GetPowerModifier(APlayerPawn * PlayerPawn) override;
};