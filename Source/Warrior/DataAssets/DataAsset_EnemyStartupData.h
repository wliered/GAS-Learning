// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "DataAsset_StartUpDataBase.h"
#include "DataAsset_EnemyStartupData.generated.h"

class UWarriorEnemyGameplayAbility;
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_EnemyStartupData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartupData")
	TArray<TSubclassOf<UWarriorEnemyGameplayAbility>> EnemyCombatAbilities;
};
