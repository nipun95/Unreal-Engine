#include "ActorRotate.h"


// Sets default values
AActorRotate::AActorRotate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PitchValue = 0.f;
	YawValue = 0.f;
	RollValue = 0.f;
}

// Called when the game starts or when spawned
void AActorRotate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorRotate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FQuat QuatRotation = FQuat(FRotator(PitchValue, YawValue, RollValue));
	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}

