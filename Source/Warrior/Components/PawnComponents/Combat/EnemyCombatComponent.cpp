// Wliered did a thing


#include "EnemyCombatComponent.h"

#include "Warrior/WarriorDebugHelper.h"


void UEnemyCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (HitActor)
	{
		Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" is hitting") + HitActor->GetActorNameOrLabel());
	}
}
