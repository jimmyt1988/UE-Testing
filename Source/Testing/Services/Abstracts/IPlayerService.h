#pragma once

#include "../../Pawns/PlayerPawn.h"

struct IPlayerService
{
	virtual int GetPowerModifier(APlayerPawn* PlayerPawn) = 0;
};