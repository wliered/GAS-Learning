// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "Warrior/Characters/WarriorBaseCharacter.h"
#include "WarriorEnemyCharacter.generated.h"

class UBoxComponent;
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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat")
	UBoxComponent* LeftHandCollisionBox;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat")
	UBoxComponent* RightHandCollisionBox;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat")
	FName LeftHandCollisionBoxAttachBoneName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat")
	FName RightHandCollisionBoxAttachBoneName;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="UI")
	UEnemyUIComponent* EnemyUIComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="UI")
	UWidgetComponent* EnemyHealthWidgetComponent;

	// Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	// End APawn Interface
#if WITH_EDITOR
	// Begin UObject Interface
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	// End UObject Interface
#endif
	
	UFUNCTION()
	virtual void OnBodyCollisionBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

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
	FORCEINLINE UBoxComponent* GetLeftHandCollisionBox() const {return LeftHandCollisionBox;}
	FORCEINLINE UBoxComponent* GetRightHandCollisionBox() const {return RightHandCollisionBox;}

private:
	void InitEnemyStartupData();
};
