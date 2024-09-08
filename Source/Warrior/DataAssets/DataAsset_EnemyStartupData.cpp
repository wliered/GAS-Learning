// Wliered did a thing


#include "DataAsset_EnemyStartupData.h"

#include "Warrior/GAS/AbilitySystemComponents/WarriorAbilitySystemComponent.h"
#include "Warrior/GAS/GameplayAbilities/WarriorEnemyGameplayAbility.h"

void UDataAsset_EnemyStartupData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive,
                                                               int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	if (!EnemyCombatAbilities.IsEmpty())
	{
		for (const TSubclassOf<UWarriorEnemyGameplayAbility>& AbilityClass :EnemyCombatAbilities)
		{
			if (!AbilityClass) continue;

			FGameplayAbilitySpec AbilitySpec(AbilityClass);
			AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
			AbilitySpec.Level = ApplyLevel;

			InASCToGive->GiveAbility(AbilitySpec);
		}
		
	}
}
