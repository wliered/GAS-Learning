// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Warrior/Components/PawnComponents/PawnExtensionComponentBase.h"
#include "Warrior/WarriorTypes/WarriorEnumTypes.h"
#include "PawnCombatComponent.generated.h"


class AWarriorWeaponBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="Warrior|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category="Warrior|Combat")
	AWarriorWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UPROPERTY(BlueprintReadWrite, Category="Warrior|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category="Warrior|Combat")
	AWarriorWeaponBase* GetCharacterCurrentEquippedWeapon() const;

	UFUNCTION(BlueprintCallable, Category="Warrior|Combat")
	void ToggleWEaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType = EToggleDamageType::CurrentEquippedWeapon);

	virtual void OnHitTargetActor(AActor* HitActor);

	virtual void OnWeaponPulledFromActor(AActor* InteractedActor);

protected:
	virtual void ToggleCurrentEquippedWeaponCollision(bool bShouldEnable);
	virtual void ToggleBodyCollisionBoxCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType);
	
	TArray<AActor*> OverlappedActors;
	
private:
	TMap<FGameplayTag, AWarriorWeaponBase*> CharacterCarriedWeaponMap;
};
