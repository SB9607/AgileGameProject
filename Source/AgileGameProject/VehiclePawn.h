// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "VehiclePawn.generated.h"

class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class AGILEGAMEPROJECT_API AVehiclePawn : public AWheeledVehicle
{
	GENERATED_BODY()
	
public:
	// Sets default values for this vehicle's properties
	AVehiclePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;

	void Throttle(float amount);
	void Steer(float amount);
	void LookUp(float amount);
	void LookRight(float amount);
};
