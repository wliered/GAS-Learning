// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WarriorWidgeBase.generated.h"

/**
 * 
 */
class UHeroUIComponent;
class UEnemyUIComponent;

UCLASS()
class WARRIOR_API UWarriorWidgeBase : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Owning Hero UI Component Initialized"))
	void BP_OnOwningHeroUIComponentInitialized(UHeroUIComponent* OwningHeroUIComponent);

public:
	UFUNCTION(BlueprintCallable)
	void  InitEnemyCreatedWidget(AActor* OwningEnemyActor);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Owning Enemy UI Component Initialized"))
	void BP_OnOwningEnemyUIComponentInitialized(UEnemyUIComponent* OwningEnemyUIComponent);

};
