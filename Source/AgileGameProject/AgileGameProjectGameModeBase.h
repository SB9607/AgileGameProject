// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AgileGameProjectGameModeBase.generated.h"

class UUserWidget;
class UGameHud;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCountdownChanged, int, StartTime);

UCLASS()
class AGILEGAMEPROJECT_API AAgileGameProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
		FTimerHandle StartHandle;
	UPROPERTY(EditAnywhere)
		int MaxLaps = 3;
	UFUNCTION()
		void GameOver(bool bWin);
	UFUNCTION()
		void CountdownTimer();

public:
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> GameHudClass;
	UPROPERTY(VisibleInstanceOnly)
		UGameHud* GameHud;
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FOnCountdownChanged OnCountdownChanged;
	UPROPERTY(VisibleAnywhere)
		int StartTime = 3;
	UPROPERTY(VisibleAnywhere)
		int NumOfLaps = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int NumOfCheckpointsNeeded = 7;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool CanStart = false;

};
