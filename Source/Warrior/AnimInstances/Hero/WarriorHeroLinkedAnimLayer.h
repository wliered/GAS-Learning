// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "Warrior/AnimInstances/WarriorBaseAnimInstance.h"
#include "WarriorHeroLinkedAnimLayer.generated.h"

/**
 * 
 */
class UWarriorHeroAnimInstance;
UCLASS()
class WARRIOR_API UWarriorHeroLinkedAnimLayer : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UWarriorHeroAnimInstance* GetHeroAnimInstance() const;
};
