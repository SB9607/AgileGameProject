// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "VehicleAIController.generated.h"

/**
 * 
 */
UCLASS()
class AGILEGAMEPROJECT_API AVehicleAIController : public AAIController
{
	GENERATED_BODY()
	
protected: 
	virtual void BeginPlay() override;
};
