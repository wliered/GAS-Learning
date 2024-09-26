// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "PawnUIComponent.h"
#include "EnemyUIComponent.generated.h"


class UWarriorWidgeBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UEnemyUIComponent : public UPawnUIComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void RegisterEnemyDrawnWidget(UWarriorWidgeBase* InWidgetToRegister);

	UFUNCTION(BlueprintCallable)
	void RemoveEnemyDrawnWidgetsIfAny();

private:
	TArray<UWarriorWidgeBase*> EnemyDrawnWidgets;
	
};
