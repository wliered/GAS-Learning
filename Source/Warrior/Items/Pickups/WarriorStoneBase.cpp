// Wliered did a thing


#include "WarriorStoneBase.h"

#include "Warrior/WarriorGameplaytags.h"
#include "Warrior/Characters/WarriorHeroCharacter.h"
#include "Warrior/GAS/AbilitySystemComponents/WarriorAbilitySystemComponent.h"


void AWarriorStoneBase::OnPickupSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AWarriorHeroCharacter* OverlappedHero = Cast<AWarriorHeroCharacter>(OtherActor))
	{
		OverlappedHero->GetWarriorAbilitySystemComponent()->TryActivateAbilityByTag(WarriorGameplayTags::Player_Ability_Pickup_Stones);
	}
}

void AWarriorStoneBase::Consume(UWarriorAbilitySystemComponent* WarriorAbilitySystemComponent, int32 ApplyLevel)
{
	check(StoneGameplayEffectClass);
	
	UGameplayEffect* EffectCDO = StoneGameplayEffectClass->GetDefaultObject<UGameplayEffect>();
	
	WarriorAbilitySystemComponent->ApplyGameplayEffectToSelf(
		EffectCDO,
		ApplyLevel,
		WarriorAbilitySystemComponent->MakeEffectContext()
	);

	BP_OnStoneConsumed();
}
