// Wliered did a thing


#include "WarriorEnemyCharacter.h"

#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Warrior/Components/PawnComponents/Combat/EnemyCombatComponent.h"
#include "Engine/AssetManager.h"
#include "Warrior/WarriorDebugHelper.h"
#include "Warrior/Components/PawnComponents/UIComponents/EnemyUIComponent.h"

#include "Warrior/DataAssets/DataAsset_StartUpDataBase.h"
#include "Warrior/Widgets/WarriorWidgeBase.h"


// Sets default values
AWarriorEnemyCharacter::AWarriorEnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()-> bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 180.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.f;

	EnemyCombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>("EnemyCombatComponent");

	EnemyUIComponent = CreateDefaultSubobject<UEnemyUIComponent>("EnemyUIComponent");

	EnemyHealthWidgetComponent = CreateDefaultSubobject<UWidgetComponent>("EnemyHealthBar");
	EnemyHealthWidgetComponent->SetupAttachment(GetMesh());
	
}

void AWarriorEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	
	if (UWarriorWidgeBase* HealthWidget = Cast<UWarriorWidgeBase>(EnemyHealthWidgetComponent->GetUserWidgetObject()))
	{
		HealthWidget->InitEnemyCreatedWidget(this);
	}
}

void AWarriorEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitEnemyStartupData();
}

UPawnCombatComponent* AWarriorEnemyCharacter::GetPawnCombatComponent() const
{
	return EnemyCombatComponent;
}

UPawnUIComponent* AWarriorEnemyCharacter::GetPawnUIComponent() const
{
	return EnemyUIComponent;
}

UEnemyUIComponent* AWarriorEnemyCharacter::GetEnemyUIComponent() const
{
	return EnemyUIComponent;
}

void AWarriorEnemyCharacter::InitEnemyStartupData()
{
	if (CharacterStartupData.IsNull())
	{
		return;
	}
	UAssetManager::GetStreamableManager().RequestAsyncLoad(
	CharacterStartupData.ToSoftObjectPath(),
	FStreamableDelegate::CreateLambda(
		[this]()
		{
			if (UDataAsset_StartUpDataBase* LoadedData = CharacterStartupData.Get())
			{
				LoadedData->GiveToAbilitySystemComponent(WarriorAbilitySystemComponent);

			}
		}
		)
	);
}


