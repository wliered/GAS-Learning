// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "WarriorPickupBase.h"
#include "WarriorStoneBase.generated.h"

class UGameplayEffect;
class UWarriorAbilitySystemComponent;

UCLASS()
class WARRIOR_API AWarriorStoneBase : public AWarriorPickupBase
{
	GENERATED_BODY()

protected:
	virtual void OnPickupSphereBeginOverlap(
	UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& SweepResult
	) override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect> StoneGameplayEffectClass;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnStoneConsumed"))
	void BP_OnStoneConsumed();

public:
	void Consume(UWarriorAbilitySystemComponent* WarriorAbilitySystemComponent, int32 ApplyLevel);
	

};
