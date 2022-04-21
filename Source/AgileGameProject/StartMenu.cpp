// Fill out your copyright notice in the Description page of Project Settings.


#include "StartMenu.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UStartMenu::NativeConstruct()
{
	// Check buttons exists and bind the buttons for click events
	if (TestButton)
	{
		TestButton->OnClicked.AddDynamic(this, &UStartMenu::OnTestClick);
	}
	if (StartButton)
	{
		StartButton->OnClicked.AddDynamic(this, &UStartMenu::OnStartClick);
	}
	if (QuitButton)
	{
		QuitButton->OnClicked.AddDynamic(this, &UStartMenu::OnQuitClick);
	}
}

void UStartMenu::OnTestClick()
{
	// When start button clicked open game level
	UWorld* World = GetWorld();
	if (World)
	{
		UGameplayStatics::OpenLevel(World, TEXT("TestLevel"));
	}
}

void UStartMenu::OnStartClick()
{
	// When start button clicked open game level
	UWorld* World = GetWorld();
	if (World)
	{
		UGameplayStatics::OpenLevel(World, TEXT("GameLevel"));
	}
}

void UStartMenu::OnQuitClick()
{
	// When quit button clicked quit and exit the game
	UWorld* World = GetWorld();
	if (World)
	{
		UKismetSystemLibrary::ExecuteConsoleCommand(World, TEXT("quit"));
	}
}

