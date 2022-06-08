// Fill out your copyright notice in the Description page of Project Settings.

#include "GameHud.h"
#include "AgileGameProjectGameModeBase.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UGameHud::NativeConstruct()
{
	if (IsValid(GoClass))
	{
		UUserWidget* Widget = CreateWidget(GetWorld(), GoClass);

		if (Widget)
		{
			Widget->AddToViewport();
		}
	}
}

