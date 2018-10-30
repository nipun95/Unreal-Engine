// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingOnCircle.h"


// Sets default values
AMovingOnCircle::AMovingOnCircle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AngleAxis = 0.f;
	
}

// Called when the game starts or when spawned
void AMovingOnCircle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingOnCircle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = NewLocationScale;

	FVector Radius = RadiusScale;

	AngleAxis++;
	if (AngleAxis > 360.0f)
	{
		AngleAxis = 1.0f;
	}

	FVector Rotatevalue = Radius.RotateAngleAxis(AngleAxis, AngleAxisScale);
	NewLocation.X += Rotatevalue.X;
	NewLocation.Y += Rotatevalue.Y;
	NewLocation.Z += Rotatevalue.Z;

	SetActorLocation(NewLocation);
}

