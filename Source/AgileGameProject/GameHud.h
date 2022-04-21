// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameHud.generated.h"

class AAgileGameProjectGameModeBase;
class UUserWidget;

UCLASS()
class AGILEGAMEPROJECT_API UGameHud : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

public:
	UFUNCTION(BlueprintCallable)
		void InitializeHud(AAgileGameProjectGameModeBase* GameModeRef);
};
