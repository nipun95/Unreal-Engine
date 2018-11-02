// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorMovingOnCircle.generated.h"

UCLASS()
class LEARNINGACTOR_API AActorMovingOnCircle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorMovingOnCircle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
		float AngleAxis;
	UPROPERTY(EditAnywhere)
	FVector NewLocationScale = FVector (0, 0, 500);
	UPROPERTY(EditAnywhere)
	FVector RadiusScale = FVector(100, 0, 0);
	UPROPERTY(EditAnywhere)
	FVector AngleAxisScale = FVector(0, 0, 1);
};
