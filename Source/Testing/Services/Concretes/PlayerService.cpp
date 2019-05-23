#include "PlayerService.h"

int PlayerService::GetPowerModifier(APlayerPawn* PlayerPawn)
{
	// Just an example for testing purposes
	return PlayerPawn->Life + PlayerPawn->Score;
}