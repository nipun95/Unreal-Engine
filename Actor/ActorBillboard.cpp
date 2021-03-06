// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorBillboard.h"
#include "Components/BillboardComponent.h"

// Sets default values
AActorBillboard::AActorBillboard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyBillComp = CreateDefaultSubobject<UBillboardComponent>(TEXT("MyBillboard"));
	MyBillComp->SetHiddenInGame(false, true);
	RootComponent = MyBillComp;
}

// Called when the game starts or when spawned
void AActorBillboard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorBillboard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

