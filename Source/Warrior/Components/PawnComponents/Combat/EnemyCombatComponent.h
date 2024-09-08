﻿// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "PawnCombatComponent.h"
#include "EnemyCombatComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UEnemyCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UEnemyCombatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
