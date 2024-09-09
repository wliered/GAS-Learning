// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimInstance.h"
#include "WarriorBaseAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadsafe))
	bool DoesOwnerHaveTag(FGameplayTag TagToCheck) const;
};
