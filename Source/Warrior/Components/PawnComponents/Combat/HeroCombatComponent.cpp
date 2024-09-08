// Wliered did a thing


#include "HeroCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Warrior/WarriorGameplaytags.h"
#include "Warrior/WarriorDebugHelper.h"
#include "Warrior/Items/Weapons/WarriorHeroWeapon.h"


AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AWarriorHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCurrentEquippedWeapon() const
{
	return Cast<AWarriorHeroWeapon>(GetCharacterCurrentEquippedWeapon());
}

float UHeroCombatComponent::GetHeroCurrentEquippedWeaponDamageAtLevel(float InLevel) const
{
	return GetHeroCurrentEquippedWeapon()->HeroWeaponData.WeaponBaseDamage.GetValueAtLevel(InLevel);
}

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}
	OverlappedActors.AddUnique(HitActor);

	FGameplayEventData Data;
	Data.Instigator = GetOwningPawn();
	Data.Target = HitActor;
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(), WarriorGameplayTags::Shared_Event_MeleeHit, Data);

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(), WarriorGameplayTags::Player_Event_HitPause, FGameplayEventData());

}

void UHeroCombatComponent::OnWeaponPulledFromActor(AActor* InteractedActor)
{
	Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT("'s weapon pulled from") + InteractedActor->GetActorNameOrLabel());
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(), WarriorGameplayTags::Player_Event_HitPause, FGameplayEventData());

}
