// Copyright Epic Games, Inc. All Rights Reserved.


#include "AgileGameProjectGameModeBase.h"
#include "GameHud.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void AAgileGameProjectGameModeBase::BeginPlay()
{
	UWorld* World = GetWorld();
	check(World);
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = false;
	NumOfLaps = 0;
	// Check widget is valid then create widget
	if (IsValid(GameHudClass))
	{
		UUserWidget* Widget = CreateWidget(GetWorld(), GameHudClass);
		// Check widget has been created then add to viewport
		if (Widget)
		{
			// Add widgets to viewport
			Widget->AddToViewport();
		}
	}
	GetWorldTimerManager().SetTimer(StartHandle, this, &AAgileGameProjectGameModeBase::CountdownTimer, 1.0f, true);

}

void AAgileGameProjectGameModeBase::CountdownTimer()
{
	if (StartTime > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Countdown: %d"), StartTime);
		StartTime -= 1;
	}
	else
	{
		if (StartHandle.IsValid())
		{
			CanStart = true;
			GetWorldTimerManager().ClearTimer(StartHandle);
		}

	}
	OnCountdownChanged.Broadcast(StartTime);
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

