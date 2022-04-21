// Fill out your copyright notice in the Description page of Project Settings.


#include "StartMenuGameModeBase.h"
#include "StartMenu.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void AStartMenuGameModeBase::BeginPlay()
{
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;

	// Check widget is valid then create widget
	if (IsValid(StartMenuClass))
	{
		UUserWidget* Widget = CreateWidget(GetWorld(), StartMenuClass);
		// Check widget has been created then add to viewport
		if (Widget)
		{
			Widget->AddToViewport();
		}
	}
}