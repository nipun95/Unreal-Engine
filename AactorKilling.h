// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ShapeComponent.h"
#include "KillingActor.generated.h"

UCLASS()
class KILLEDBYACTOR_API AKillingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKillingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = Root, meta = (AllowPrivateAccess = true))
		class UShapeComponent* tRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = Root, meta = (AllowPrivateAccess = true))
		class UStaticMeshComponent* MyMesh;

	//Called for Moving Actor
	UPROPERTY(EditAnywhere)
		float SpeedScale;
	UPROPERTY(EditAnywhere)
		bool MovetoXAxis = true;

		float DeltaMove;
		float Runtime;

	//Called for Killing Character
	FVector PlayerStartingLocation = FVector(-1760.0f, -310.0f, 266.2f);
	FVector BoxSize = FVector(3.0f, 6.0f, 6.0f);
	UFUNCTION()
		void TriggerEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& SweepResult);
	
};
