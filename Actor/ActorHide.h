// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorHide.generated.h"

UCLASS()
class ******** AHideActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorHide();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = "Disable")
		bool HideInGame;

	UFUNCTION(BlueprintCallable, Category = "Disable")
		void DisableActor();
	
};
