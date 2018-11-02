// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorFinishLine.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AActorFinishLine::AActorFinishLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FinishLine = CreateDefaultSubobject<UBoxComponent>(TEXT("FinishLine"));
	FinishLine->SetGenerateOverlapEvents(true);
	FinishLine->OnComponentEndOverlap.AddDynamic(this, &AFinishLine::TriggerExit);
	FinishLine->SetWorldScale3D(BoxSize);
	RootComponent = FinishLine;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

// Called when the game starts or when spawned
void AActorFinishLine::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AActorFinishLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*void AActorFinishLine::TriggerEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		FString Win = FString::Printf(TEXT("Congratulation! You have won the game...."));
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Yellow, Win);
		//Destroy();
	}
}*/

void AActorFinishLine::TriggerExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	FString Win = FString::Printf(TEXT("Congratulation! You have won the game...."));
	GEngine->AddOnScreenDebugMessage(1, 5, FColor::Yellow, Win);
}
