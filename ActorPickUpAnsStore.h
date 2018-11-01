// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ShapeComponent.h"
#include "ActorPickUp.generated.h"


UCLASS()
class LEARNINGACTOR_API AActorPickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorPickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = Pickup, meta = (AllowPrivateAccess = true))
		UShapeComponent* BoxCollider;
	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = Pickup, meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* MyMesh;
	UPROPERTY(EditAnywhere)
		float Speed;
	UPROPERTY(EditAnywhere)
		FRotator RotationRate = FRotator(100.0f, 0.0f, 0.0f);
	UPROPERTY(EditAnywhere)
		FString Name;
	virtual void OnInteract();


	//Overlap function
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult& SweepResult);
	
};
