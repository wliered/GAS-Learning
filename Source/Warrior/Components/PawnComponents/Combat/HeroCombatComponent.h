// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"


class AWarriorHeroWeapon;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorHeroWeapon* GetHeroCarriedWeaponByTag (FGameplayTag InWeaponTag) const;

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorHeroWeapon* GetHeroCurrentEquippedWeapon () const;

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	float GetHeroCurrentEquippedWeaponDamageAtLevel (float InLevel) const;
	
	virtual void OnHitTargetActor(AActor* HitActor) override;

	virtual void OnWeaponPulledFromActor(AActor* InteractedActor) override;
};
