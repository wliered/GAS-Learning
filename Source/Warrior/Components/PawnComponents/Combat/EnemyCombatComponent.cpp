// Wliered did a thing


#include "EnemyCombatComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Warrior/WarriorDebugHelper.h"
#include "Warrior/WarriorGameplaytags.h"


void UEnemyCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}
	//this array is cleared in the combat component base when we disable the weapon collision
	OverlappedActors.AddUnique(HitActor);

	//TODO: implement block check
	bool bIsValidBlock = false;
	const bool bIsPlayerBlocking = false;
	const bool bIsMyAttackUnblockable = false;

	if (bIsPlayerBlocking && !bIsMyAttackUnblockable)
	{
		//TODO: check if block is valid
	}

	// create event data to be used as an out param in the function below
	FGameplayEventData EventData;
	EventData.Instigator = GetOwningPawn();
	EventData.Target = HitActor;
	
	if (bIsValidBlock)
	{
		//TODO: handle successful block
	}
	else
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(), WarriorGameplayTags::Shared_Event_MeleeHit, EventData);
	}
}
