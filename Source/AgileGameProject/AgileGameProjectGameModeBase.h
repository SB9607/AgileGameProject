// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AgileGameProjectGameModeBase.generated.h"

class UUserWidget;
class UGameHud;

UCLASS()
class AGILEGAMEPROJECT_API AAgileGameProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
		int NumOfLaps = 0;
	UPROPERTY(VisibleAnywhere)
		int MaxLaps = 3;
	UFUNCTION()
		void GameOver(bool bWin);

public:
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> GameHudClass;

	UPROPERTY(VisibleInstanceOnly)
		UGameHud* GameHud;

};
