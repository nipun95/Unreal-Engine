// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorHide.h"


// Sets default values
AActorHide::AActorHide()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
}

// Called when the game starts or when spawned
void AActorHide::BeginPlay()
{
	Super::BeginPlay();
	
	if (HideInGame)
	{
		DisableActor();
	}

	
}

// Called every frame
void AActorHide::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActorHide::DisableActor()
{
	SetActorHiddenInGame(true);

	SetActorEnableCollision(false);

	SetActorTickEnabled(false);
}
