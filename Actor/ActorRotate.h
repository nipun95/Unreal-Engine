#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorRotate.generated.h"

UCLASS()
class LEARNINGACTOR_API AActorRotate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorRotate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, Category = "Movement")
		float PitchValue;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float YawValue;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float RollValue;

};
