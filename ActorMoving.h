#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KillingActor.generated.h"

UCLASS()
class KILLEDBYACTOR_API AKillingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKillingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

  //Called for Mash/Component
	UPROPERTY()
		class USphereComponent* tRoot;
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* MyMesh;

	//Called for Moving Actor
	UPROPERTY(EditAnywhere, Category = "Speed Scale");
		float SpeedScale;
	UPROPERTY(EditAnywhere)
		bool MovetoXAxis = true;

		float DeltaMove;
		float Runtime;

};
