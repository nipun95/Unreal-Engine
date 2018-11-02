// Fill out your copyright notice in the Description page of Project Settings.

#include "KillingActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "DrawDebugHelpers.h"


// Sets default values
AKillingActor::AKillingActor()
{

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpeedScale = 00.0f;

	tRoot = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	tRoot->SetGenerateOverlapEvents(true);
	tRoot->OnComponentBeginOverlap.AddDynamic(this, &AKillingActor::TriggerEnter);
	tRoot->SetWorldScale3D(BoxSize);
	RootComponent = tRoot;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	
}

// Called when the game starts or when spawned
void AKillingActor::BeginPlay()
{
	Super::BeginPlay();
	
	DrawDebugSphere(GetWorld(), GetActorLocation(), 300.0f, 50, FColor::Green, true, -1, 0, 2);
}

// Called every frame
void AKillingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	DeltaMove = (FMath::Sin(Runtime + DeltaTime) - FMath::Sin(Runtime));
	if(MovetoXAxis)
		NewLocation.Y += DeltaMove * SpeedScale;
	else
		NewLocation.X += DeltaMove * SpeedScale;
	Runtime += DeltaTime;
	SetActorLocation(NewLocation);
}


void AKillingActor::TriggerEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	//Start from begining point
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		FString ReStart = FString::Printf(TEXT("The game has been Restart"));
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Yellow, ReStart);
		OtherActor->SetActorLocation(PlayerStartingLocation);
	}
}
