// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Warrior/WarriorTypes/WarriorEnumTypes.h"
#include "WarriorSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	EWarriorGameDifficulty SavedCurrentDifficultyLevel;
};
