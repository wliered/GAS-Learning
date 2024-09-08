// Wliered did a thing


#include "WarriorAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Warrior/WarriorDebugHelper.h"
#include "Warrior/Components/PawnComponents/UIComponents/HeroUIComponent.h"
#include "Warrior/WarriorFunctionLibrary.h"
#include "Warrior/WarriorGameplaytags.h"
#include "Warrior/Components/PawnComponents/UIComponents/PawnUIComponent.h"
#include "Warrior/Interfaces/PawnUIInterface.h"

UWarriorAttributeSet::UWarriorAttributeSet()
{
	InitCurrentHealth(1.f);
	InitMaxHealth(1.f);
	InitCurrentRage(1.f);
	InitMaxRage(1.f);
	InitAttackPower(1.f);
	InitDefensePower(1.f);
}

void UWarriorAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if(!CachedPawnUIInterface.IsValid())
	{
		CachedPawnUIInterface = TWeakInterfacePtr<IPawnUIInterface>(Data.Target.GetAvatarActor());
	}

	checkf(CachedPawnUIInterface.IsValid(), TEXT("%s didn't implement IPawnUIInterface"), *Data.Target.GetAvatarActor()->GetActorNameOrLabel());
	UPawnUIComponent* PawnUIComponent = CachedPawnUIInterface->GetPawnUIComponent();

	checkf(PawnUIComponent, TEXT("Couldn't extract a PAwnUIComponent from %s"), *Data.Target.GetAvatarActor()->GetActorNameOrLabel());
	
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);
		
		PawnUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHealth()/GetMaxHealth());
	}

	if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
	{
		const float NewCurrentRage = FMath::Clamp(GetCurrentRage(), 0.f, GetMaxRage());

		SetCurrentRage(NewCurrentRage);
		
		if(UHeroUIComponent* HeroUIComponent = CachedPawnUIInterface->GetHeroUIComponent())
		{
			HeroUIComponent->OnCurrentRageChanged.Broadcast(GetCurrentRage()/GetMaxRage());
		}
	}

	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float OldHealth = GetCurrentHealth();
		const float DamageDone = GetDamageTaken();
		const float NewCurrentHealth = FMath::Clamp(OldHealth-DamageDone, 0.f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);
		//const FString DebugString = FString::Printf( TEXT("Old Health: %f, Damage Done: %f, NewCurrentHealth: %f"), OldHealth, DamageDone, NewCurrentHealth);
		//Debug::Print(DebugString);

		PawnUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHealth()/GetMaxHealth());
		
		if (GetCurrentHealth() == 0.f)
		 {
		//HandleDeath() this is cool because we're doing it simply by adding the status tag, which will trigger the Death ability when added
		 	UWarriorFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), WarriorGameplayTags::Shared_Status_Dead);
		 }
		 
	}

	
}
