// Wliered did a thing


#include "WarriorWidgeBase.h"
#include "Blueprint/UserWidget.h"
#include "Warrior/Interfaces/PawnUIInterface.h"

void UWarriorWidgeBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(GetOwningPlayerPawn()))
	{
		if (UHeroUIComponent* HeroUIComponent = PawnUIInterface->GetHeroUIComponent())
		{
			BP_OnOwningHeroUIComponentInitialized(HeroUIComponent);
		}
	}
}

void UWarriorWidgeBase::InitEnemyCreatedWidget(AActor* OwningEnemyActor)
{
	if (IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(OwningEnemyActor))
	{
		UEnemyUIComponent* EnemyUIComponent = PawnUIInterface->GetEnemyUIComponent();

		checkf(EnemyUIComponent, TEXT("EnemyUIComponent is unable to be extracted from %s"), *OwningEnemyActor->GetActorNameOrLabel());

		BP_OnOwningEnemyUIComponentInitialized(EnemyUIComponent);
	}
}
