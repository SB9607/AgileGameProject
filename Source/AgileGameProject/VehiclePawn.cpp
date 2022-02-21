// Fill out your copyright notice in the Description page of Project Settings.


#include "VehiclePawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "WheeledVehicleMovementComponent.h"

// Sets default values
AVehiclePawn::AVehiclePawn()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->AttachTo(RootComponent);
	SpringArm->TargetArmLength = 400.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->AttachToComponent(SpringArm, FAttachmentTransformRules::KeepRelativeTransform);
	Camera->SetRelativeLocation(FVector(-400.0f, 0.0f, 300.0f));
	Camera->SetRelativeRotation(FRotator(0.0f, -30.0f, 0.0f));
}

// Called when the game starts or when spawned
void AVehiclePawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AVehiclePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AVehiclePawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Throttle", this, &AVehiclePawn::Throttle);
	PlayerInputComponent->BindAxis("Steer", this, &AVehiclePawn::Steer);
	PlayerInputComponent->BindAxis("Look Up", this, &AVehiclePawn::LookUp);
	PlayerInputComponent->BindAxis("Look Right", this, &AVehiclePawn::LookRight);
}

void AVehiclePawn::Throttle(float amount)
{
	GetVehicleMovementComponent()->SetThrottleInput(amount);
}

void AVehiclePawn::Steer(float amount)
{
	GetVehicleMovementComponent()->SetSteeringInput(amount);
}
	
void AVehiclePawn::LookUp(float amount)
{
	AddControllerPitchInput(amount);
}
	
void AVehiclePawn::LookRight(float amount)
{
	AddControllerYawInput(amount);
}
