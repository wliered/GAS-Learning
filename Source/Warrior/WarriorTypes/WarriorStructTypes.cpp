// Wliered did a thing


#include "Warrior/WarriorTypes/WarriorStructTypes.h"

#include "Warrior/GAS/GameplayAbilities/WarriorGameplayAbility.h"
#include "Warrior/GAS/GameplayAbilities/WarriorHeroGameplayAbility.h"

bool FWarriorHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
