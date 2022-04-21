// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StartMenuGameModeBase.generated.h"

class UUserWidget;

UCLASS()
class AGILEGAMEPROJECT_API AStartMenuGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> StartMenuClass;
};
