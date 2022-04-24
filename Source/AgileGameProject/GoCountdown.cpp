// Fill out your copyright notice in the Description page of Project Settings.


#include "GoCountdown.h"
#include "AgileGameProjectGameModeBase.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Animation/WidgetAnimation.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UGoCountdown::NativeConstruct()
{
	Super::NativeConstruct();
	// Bind go animation to trigger finished animation event
	BindToAnimationFinished(GoAnimation, GoAnimationFinished);
	// Cast game mode
	GameModeRef = Cast<AAgileGameProjectGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameModeRef)
	{
		// Set initial timer output and add countdown changed event
		StartCountdown->SetText(FText::AsNumber(3));
		GameModeRef->OnCountdownChanged.AddDynamic(this, &UGoCountdown::SetStartCountdown);
	}
}

void UGoCountdown::SetStartCountdown(int Countdown)
{

	// Display countdown timer 3,2,1
	StartCountdown->SetText(FText::AsNumber(Countdown));
	// When timer is equal to 0
	if (GameModeRef->StartTime == 0)
	{
		// Set visibility for start countdown to hidden
		StartCountdown->SetVisibility(ESlateVisibility::Hidden);
		// Call go animation
		PlayGoAnimation();
	}
}

void UGoCountdown::PlayGoAnimation()
{
	if (Go)
	{
		// Set go visibility to visible 
		Go->SetVisibility(ESlateVisibility::Visible);
		if (GoAnimation)
		{
			// Play go animation
			PlayAnimationForward(GoAnimation, 1.0f);
		}
	}
}

void UGoCountdown::OnAnimationFinished(UWidgetAnimation* Animation)
{
	// when animation has finished remove widget for the screen
	if (Animation)
	{
		RemoveFromParent();
	}
}
