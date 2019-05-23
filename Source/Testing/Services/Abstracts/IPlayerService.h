#pragma once

#include "Common.h"
#include "../../Pawns/PlayerPawn.h"

struct IPlayerService
{
public:
	virtual int GetPowerModifier(class APlayerPawn* PlayerPawn) = 0;
};

Expose_TNameOf(IPlayerService)