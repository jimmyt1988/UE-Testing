#include "../Abstracts/IPlayerService.h"
#include "../../Pawns/PlayerPawn.h"

class PlayerService : public IPlayerService
{
	virtual int GetPowerModifier(APlayerPawn* PlayerPawn) override;
};