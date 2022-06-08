// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameOverMenuGameModeBase.generated.h"

class UUserWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameOver, bool, Win);

UCLASS()
class AGILEGAMEPROJECT_API AGameOverMenuGameModeBase : public AGameMode
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> GameOverMenuClass;

public:
	UPROPERTY(BlueprintCallable)
		FOnGameOver OnGameOver;
};
