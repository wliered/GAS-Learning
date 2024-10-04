// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WarriorPickupBase.generated.h"

class USphereComponent;

UCLASS()
class WARRIOR_API AWarriorPickupBase : public AActor
{
	GENERATED_BODY()

public:
	AWarriorPickupBase();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PickUp Interaction")
	USphereComponent* PickupCollisionSphere;

	UFUNCTION()
	virtual void OnPickupSphereBeginOverlap(
    UPrimitiveComponent* OverlappedComponent, 
    AActor* OtherActor, 
    UPrimitiveComponent* OtherComp, 
    int32 OtherBodyIndex, 
    bool bFromSweep, 
    const FHitResult& SweepResult
	);
};
