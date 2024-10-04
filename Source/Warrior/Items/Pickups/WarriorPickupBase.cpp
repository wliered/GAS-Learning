// Wliered did a thing


#include "WarriorPickupBase.h"

#include "Components/SphereComponent.h"


AWarriorPickupBase::AWarriorPickupBase()
{
	PrimaryActorTick.bCanEverTick = false;

	PickupCollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Pickup Collision Sphere"));
	SetRootComponent(PickupCollisionSphere);
	PickupCollisionSphere->InitSphereRadius(50.f);
	PickupCollisionSphere->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::AWarriorPickupBase::OnPickupSphereBeginOverlap);
}

void AWarriorPickupBase::OnPickupSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}



