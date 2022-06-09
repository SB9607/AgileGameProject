// Fill out your copyright notice in the Description page of Project Settings.

#include "GameOverMenu.h"
#include "GameOverMenuGameModeBase.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UGameOverMenu::NativeConstruct()
{
	// Get reference to game mode
	GameModeRef = Cast<AGameOverMenuGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameModeRef)
	{
		GameModeRef->OnGameOver.AddDynamic(this, &UGameOverMenu::ShowWinLoose);
	}
	// Check buttons exists and bind the buttons for click events
	if (MainMenuButton)
	{
		MainMenuButton->OnClicked.AddDynamic(this, &UGameOverMenu::OnMainMenuClick);
	}
	if (QuitButton)
	{
		QuitButton->OnClicked.AddDynamic(this, &UGameOverMenu::OnQuitClick);
	}
}

void UGameOverMenu::ShowWinLoose(bool Win)
{
	// UE_LOG(LogTemp, Warning, TEXT("win/lose"));
	// Set win text to  display win or loose based on win condition passed from game mode
	if (Win == true)
	{
		WinText->SetText(FText::FromString("You Win!"));
	}
	else
	{
		WinText->SetText(FText::FromString("You Lose!"));
	}
}

void UGameOverMenu::OnMainMenuClick()
{
	// When start button clicked open game level
	UWorld* World = GetWorld();
	if (World)
	{
		UGameplayStatics::OpenLevel(World, TEXT("StartLevel"));
	}
}

void UGameOverMenu::OnQuitClick()
{
	// When quit button clicked quit and exit the game
	UWorld* World = GetWorld();
	if (World)
	{
		UKismetSystemLibrary::ExecuteConsoleCommand(World, TEXT("quit"));
	}
}
