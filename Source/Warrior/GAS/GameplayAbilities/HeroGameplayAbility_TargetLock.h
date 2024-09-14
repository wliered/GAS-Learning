// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "WarriorHeroGameplayAbility.h"
#include "HeroGameplayAbility_TargetLock.generated.h"

class UInputMappingContext;
class UWarriorWidgeBase;
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

	UFUNCTION(BlueprintCallable)
	void OnTargetLockTick(float DeltaTime);
	

private:
	void TryLockOnTarget();
	void GetAvailableActorsToLock();
	AActor* GetNearestTargetFromAvailableActors(const TArray<AActor*>& InAvailableActors);
	void DrawTargetLockWidget();
	void SetTargetLockWidgetPoistion();
	void InitTargetLockMovement();
	void InitTargetLockMappingContext();
	void ResetTargetLockMappingContext();

	void CancelTargetLockAbility();
	void CleanUp();
	void ResetTargetLockMovement();

	UPROPERTY(EditDefaultsOnly, Category="TargetLock")
	float BoxTraceDistance = 5000.f;
	UPROPERTY(EditDefaultsOnly, Category="TargetLock")
	FVector BoxTraceSize = FVector(5000.f, 5000.f, 300.f);
	UPROPERTY(EditDefaultsOnly, Category="TargetLock")
	TArray<TEnumAsByte<EObjectTypeQuery> > BoxTraceChannel;
	UPROPERTY(EditDefaultsOnly, Category="TargetLock")
	bool bShowPersistentDebugShape = false;
	UPROPERTY(EditDefaultsOnly, Category="TargetLock")
	TSubclassOf<UWarriorWidgeBase> TargetLockWidgetClass; //creates a hard reference of a widget, but this one is simple, small, and frequently used so it is justifiable
	UPROPERTY(EditDefaultsOnly, Category="TargetLock")
	float TargetLockRotationInterpSpeed = 5.f;
	UPROPERTY(EditDefaultsOnly, Category="TargetLock")
	float TargetLockMaxWalkSpeed = 200.f;
	UPROPERTY(EditDefaultsOnly, Category="TargetLock")
	UInputMappingContext* TargetLockMappingContext;

	UPROPERTY()
	TArray<AActor*> AvailableActorsToTarget;
	UPROPERTY()
	AActor* CurrentLockedActor;
	UPROPERTY()
	UWarriorWidgeBase* DrawnTargetLockWidget;
	UPROPERTY()
	FVector2D TargetLockWidgetSize = FVector2D::ZeroVector;

	UPROPERTY()
	float CachedDefaultMaxWalkSpeed = 0.f;
};
