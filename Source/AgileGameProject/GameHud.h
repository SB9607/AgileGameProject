// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameHud.generated.h"

class AAgileGameProjectGameModeBase;
class UTextBlock;

UCLASS()
class AGILEGAMEPROJECT_API UGameHud : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(VisibleInstanceOnly)
		AAgileGameProjectGameModeBase* GameModeRef;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<UUserWidget> GoClass;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* SpeedText;
	UFUNCTION(BlueprintCallable)
		void DisplaySpeed(FString speed);
};
