#include "ActorMoving.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"



// Sets default values
AActorMoving::AActorMoving()
{

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	tRoot = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->AttachTo(tRoot);

	SpeedScale = 00.0f;
}

// Called when the game starts or when spawned
void AActorMoving::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AActorMoving::Tick(float DeltaTime)
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
};
