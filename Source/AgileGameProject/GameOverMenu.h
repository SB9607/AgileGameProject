// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverMenu.generated.h"

class UButton;
class UTextBlock;
class AGameOverMenuGameModeBase;

UCLASS()
class AGILEGAMEPROJECT_API UGameOverMenu : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(VisibleInstanceOnly)
		AGameOverMenuGameModeBase* GameModeRef;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* MainMenuButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UButton* QuitButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* WinText;

	UFUNCTION()
		void ShowWinLoose(bool Win);
	UFUNCTION()
		void OnMainMenuClick();
	UFUNCTION()
		void OnQuitClick();
};
