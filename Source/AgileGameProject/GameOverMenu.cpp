// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverMenu.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UGameOverMenu::NativeConstruct()
{
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


