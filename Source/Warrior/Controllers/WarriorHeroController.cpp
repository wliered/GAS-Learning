// Wliered did a thing


#include "WarriorHeroController.h"

AWarriorHeroController::AWarriorHeroController()
{
	HeroTeamID = FGenericTeamId(0);
}

FGenericTeamId AWarriorHeroController::GetGenericTeamId() const
{
	return HeroTeamID;
}
