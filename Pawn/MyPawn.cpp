// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawn.h"
#include "GameFramework/Pawn.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"


// Sets default values
AMyPawn::AMyPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("CubeMesh");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Moveforward", this, &AMyPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPawn::MoveRight);
}

void AMyPawn::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void AMyPawn::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

