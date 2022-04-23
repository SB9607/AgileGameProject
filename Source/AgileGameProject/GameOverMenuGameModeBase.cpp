// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverMenuGameModeBase.h"
#include "GameOverMenu.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void AGameOverMenuGameModeBase::BeginPlay()
{
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;

	// Check widget is valid then create widget
	if (IsValid(GameOverMenuClass))
	{
		UUserWidget* Widget = CreateWidget(GetWorld(), GameOverMenuClass);
		// Check widget has been created then add to viewport
		if (Widget)
		{
			Widget->AddToViewport();
		}
	}
}
