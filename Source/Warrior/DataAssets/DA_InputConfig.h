// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "DA_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FWarriorInputActionConfig
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputAction;

	bool IsValid() const
	{
		return InputTag.IsValid() && InputAction;
	}

	
};
/**
 * 
 */
UCLASS()
class WARRIOR_API UDA_InputConfig : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag")) // the TitleProperty meta specifier makes the rows inside the array use the text as their name
	TArray<FWarriorInputActionConfig>NativeInputActions;
	
	UInputAction* FindNativeInputActionByTag(const FGameplayTag& InInputTag) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag")) 
	TArray<FWarriorInputActionConfig> AbilityInputActions;
};
