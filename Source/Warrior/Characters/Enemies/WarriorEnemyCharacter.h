// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "Warrior/Characters/WarriorBaseCharacter.h"
#include "WarriorEnemyCharacter.generated.h"

class UWidgetComponent;
class UEnemyUIComponent;
class UEnemyCombatComponent;

UCLASS()
class WARRIOR_API AWarriorEnemyCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarriorEnemyCharacter();

protected:

	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat")
	UEnemyCombatComponent* EnemyCombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="UI")
	UEnemyUIComponent* EnemyUIComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="UI")
	UWidgetComponent* EnemyHealthWidgetComponent;

	// Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	// End APawn Interface

public:
	//Begin IPawnCombatInterface
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//End IPawnCombatInterface

	//Begin IPawnUIInterface
	virtual UPawnUIComponent* GetPawnUIComponent() const override;
	virtual UEnemyUIComponent* GetEnemyUIComponent() const override;
	//End IPawnUIInterface

public:
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent;}

private:
	void InitEnemyStartupData();
};
