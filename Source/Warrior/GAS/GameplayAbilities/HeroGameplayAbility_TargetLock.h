﻿// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "WarriorHeroGameplayAbility.h"
#include "HeroGameplayAbility_TargetLock.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UHeroGameplayAbility_TargetLock : public UWarriorHeroGameplayAbility
{
	GENERATED_BODY()
	
protected:
	//Begin UGameplayAbility Interface
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//End UGameplayAbility Interface

private:
	void TryLockOnTarget();
	void GetAvailableActorsToLock();

	UPROPERTY(EditDefaultsOnly, Category="TargetLock")
	float BoxTraceDistance = 5000.f;
	UPROPERTY(EditDefaultsOnly, Category="TargetLock")
	FVector BoxTraceSize = FVector(5000.f, 5000.f, 300.f);
	UPROPERTY(EditDefaultsOnly, Category="TargetLock")
	TArray<TEnumAsByte<EObjectTypeQuery> > BoxTraceChannel;
	UPROPERTY(EditDefaultsOnly, Category="TargetLock")
	bool bShowPersistentDebugShape = false;
	UPROPERTY()
	TArray<AActor*> AvailableActorsToTarget;
};
