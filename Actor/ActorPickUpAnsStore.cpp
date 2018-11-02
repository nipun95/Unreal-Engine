// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorPickUpAnsStore.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
AActorPickUpAnsStore::AActorPickUpAnsStore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Speed = 1.0f;
	

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	BoxCollider->SetGenerateOverlapEvents (true);
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AActorPickUp::OnBeginOverlap);
	RootComponent = BoxCollider;
	BoxCollider->SetWorldScale3D(FVector(0.5f, 0.5f, .015f));
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
	MyMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		
}

void AActorPickUpAnsStore::OnInteract()
{
	FString pickup = FString::Printf(TEXT("Picked up: %s"), *Name);
	GEngine->AddOnScreenDebugMessage(1, 5, FColor::Yellow, pickup);
	Destroy();
}

void AActorPickUpAnsStore::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		FString pickup = FString::Printf(TEXT("Picked up: %s"), *GetName());
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Yellow, pickup);
		OnInteract();
	}
}

// Called when the game starts or when spawned
void AActorPickUpAnsStore::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorPickUpAnsStore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(RotationRate * DeltaTime * Speed);
}

