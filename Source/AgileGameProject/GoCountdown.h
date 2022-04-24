// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GoCountdown.generated.h"

class AAgileGameProjectGameModeBase;
class UTextBlock;
class UWidgetAnimation;
class FWidgetAnimationDynamicEvent;

UCLASS()
class AGILEGAMEPROJECT_API UGoCountdown : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

private:
	void OnAnimationFinished(UWidgetAnimation* Animation);
	UPROPERTY(VisibleInstanceOnly)
		FWidgetAnimationDynamicEvent GoAnimationFinished;
	UPROPERTY(VisibleInstanceOnly)
		AAgileGameProjectGameModeBase* GameModeRef;
	UPROPERTY(Transient, meta = (BindWidgetAnim))
		UWidgetAnimation* GoAnimation;
	UFUNCTION(BlueprintCallable)
		void PlayGoAnimation();
	
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StartCountdown;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Go;
	UFUNCTION(BlueprintCallable)
		void SetStartCountdown(int Countdown);
};
