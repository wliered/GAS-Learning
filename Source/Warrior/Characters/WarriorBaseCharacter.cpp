// Wliered did a thing


#include "WarriorBaseCharacter.h"

#include "Warrior/GAS/AbilitySystemComponents/WarriorAbilitySystemComponent.h"
#include "Warrior/GAS/AttributeSets/WarriorAttributeSet.h"


// Sets default values
AWarriorBaseCharacter::AWarriorBaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	WarriorAbilitySystemComponent = CreateDefaultSubobject<UWarriorAbilitySystemComponent>(TEXT("WarriorAbilitySystemComponent"));

	WarriorAttributeSet = CreateDefaultSubobject<UWarriorAttributeSet>(TEXT("WarriorAttributeSet"));
}

UAbilitySystemComponent* AWarriorBaseCharacter::GetAbilitySystemComponent() const
{
	return GetWarriorAbilitySystemComponent();
}

UPawnCombatComponent* AWarriorBaseCharacter::GetPawnCombatComponent() const
{
	return nullptr;
}

UPawnUIComponent* AWarriorBaseCharacter::GetPawnUIComponent() const
{
	return nullptr;
}

UHeroUIComponent* AWarriorBaseCharacter::GetHeroUIComponent() const
{
	return nullptr;
}

UEnemyUIComponent* AWarriorBaseCharacter::GetEnemyUIComponent() const
{
	return nullptr;
}

void AWarriorBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (WarriorAbilitySystemComponent)
	{
		WarriorAbilitySystemComponent->InitAbilityActorInfo(this, this);
		ensure(!CharacterStartupData.IsNull());
		ensureMsgf(!CharacterStartupData.IsNull(), TEXT("Forgot to assign StartupData to %s"), *GetName());
	}
}
