// Copyright Epic Games, Inc. All Rights Reserved.


#include "AgileGameProjectGameModeBase.h"
#include "GameHud.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void AAgileGameProjectGameModeBase::BeginPlay()
{
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = false;
	NumOfLaps = 0;

	// Check widget is valid then create widget
	if (IsValid(GameHudClass))
	{
		UUserWidget* Widget = CreateWidget(GetWorld(), GameHudClass);
		// Check widget has been created then add to viewport
		if (Widget)
		{
			// Initialize hud
			GameHud->InitializeHud(this);
			// Add widgets to viewport
			Widget->AddToViewport();
		}
	}
}

void AAgileGameProjectGameModeBase::GameOver(bool bWin)
{
	UE_LOG(LogTemp, Warning, TEXT("Game Over"));
	UWorld* World = GetWorld();
	if (World)
	{
		if (bWin == true)
		{
			UGameplayStatics::OpenLevel(World, TEXT("EndLevel"));
		}
	}
}

