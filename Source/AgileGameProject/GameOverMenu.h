// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverMenu.generated.h"

class UButton;

UCLASS()
class AGILEGAMEPROJECT_API UGameOverMenu : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* MainMenuButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* QuitButton;

	UFUNCTION()
		void OnMainMenuClick();
	UFUNCTION()
		void OnQuitClick();
};
