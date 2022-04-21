// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StartMenu.generated.h"

class UButton;

UCLASS()
class AGILEGAMEPROJECT_API UStartMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* TestButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* StartButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* QuitButton;

	UFUNCTION()
		void OnTestClick();
	UFUNCTION()
		void OnStartClick();
	UFUNCTION()
		void OnQuitClick();

};
