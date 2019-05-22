#include "PlayerService.h"

int PlayerService::GetPowerModifier(APlayerPawn* PlayerPawn)
{
	// Just an example
	return PlayerPawn->Life + PlayerPawn->Score;
}