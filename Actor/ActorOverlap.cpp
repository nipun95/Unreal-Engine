// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorOverlap.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
AActorOverlap::AActorOverlap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LightIntensity = 3000.f;
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Point Light"));
	PointLight->Intensity = LightIntensity;
	PointLight->bVisible = true;
	RootComponent = PointLight;

	LightSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Light Sphere"));
	LightSphere->InitSphereRadius(300.f);
	LightSphere->SetCollisionProfileName(TEXT("Trigger"));
	LightSphere->SetupAttachment(RootComponent);

	LightSphere->OnComponentBeginOverlap.AddDynamic(this, &AActorOverlap::OnOverlapBegin);
	LightSphere->OnComponentEndOverlap.AddDynamic(this, &AActorOverlap::OnOverlapEnd);

}

// Called when the game starts or when spawned
void AActorOverlap::BeginPlay()
{
	Super::BeginPlay();
	
	DrawDebugSphere(GetWorld(), GetActorLocation(), 300.0f, 50, FColor::Green,true, -1, 0, 2);
}

// Called every frame
void AActorOverlap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActorOverlap::ToggleLight()
{
	PointLight->ToggleVisibility();
}

void AActorOverlap::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//if (OtherActor && (OtherActor != this) && OtherActor)
	//{
		ToggleLight();
	//}
}
void AActorOverlap::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherActor)
	{
		ToggleLight();
	}
}
