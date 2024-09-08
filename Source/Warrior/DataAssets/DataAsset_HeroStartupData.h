// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "DataAsset_StartUpDataBase.h"
#include "Warrior/WarriorTypes/WarriorStructTypes.h"
#include "DataAsset_HeroStartupData.generated.h"

//struct FWarriorHeroAbilitySet;

UCLASS()
class WARRIOR_API UDataAsset_HeroStartupData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartupData", meta = (TitleProperty = "InputTag"))
	TArray<FWarriorHeroAbilitySet> HeroStartupAbilitySets;

};
