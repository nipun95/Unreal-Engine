// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ShapeComponent.h"
#include "ActorFinishLine.generated.h"

UCLASS()
class KILLEDBYACTOR_API AActorFinishLine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorFinishLine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = Finishedline, meta = (AllowPrivateAccess = true))
		 UShapeComponent* FinishLine;
	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = Finishedline, meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* MyMesh;

	FVector BoxSize = FVector(3.0f, 6.0f, 6.0f);

	UFUNCTION()
		void TriggerEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& SweepResult);
	UFUNCTION()
		void TriggerExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
