#pragma once

#include "Common.h"
#include "../Abstracts/IPlayerService.h"
#include "../../Pawns/PlayerPawn.h"

class PlayerService : public IPlayerService
{
	// Inherited via IPlayerService
	virtual int GetPowerModifier(APlayerPawn * PlayerPawn) override;
};