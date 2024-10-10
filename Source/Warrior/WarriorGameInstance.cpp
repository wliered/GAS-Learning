// Wliered did a thing


#include "WarriorGameInstance.h"
#include "MoviePlayer.h"

void UWarriorGameInstance::OnPreloadMap(const FString& MapName)
{
	FLoadingScreenAttributes LoadingScrenAttributes;
	LoadingScrenAttributes.bAutoCompleteWhenLoadingCompletes=true;
	LoadingScrenAttributes.MinimumLoadingScreenDisplayTime=2.f;
	LoadingScrenAttributes.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();

	GetMoviePlayer()->SetupLoadingScreen(LoadingScrenAttributes);
}

void UWarriorGameInstance::OnDestinationWorldLoaded(UWorld* LoadedWorld)
{
	GetMoviePlayer()->StopMovie();
}

TSoftObjectPtr<UWorld> UWarriorGameInstance::GetGameLevelByTag(FGameplayTag InTag) const
{
	for (const FWarriorGameLevelSet& GameLevelSet : GameLevelSets)
	{
		if (!GameLevelSet.IsValid()) continue;

		if (GameLevelSet.LevelTag == InTag)
		{
			return GameLevelSet.Level;
		}
	}

	return TSoftObjectPtr<UWorld>();
}

void UWarriorGameInstance::Init()
{
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UWarriorGameInstance::OnPreloadMap);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UWarriorGameInstance::OnDestinationWorldLoaded);
}
