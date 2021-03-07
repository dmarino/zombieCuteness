// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeadlyPickUp.generated.h"

class UShapeComponent;




enum class PICKUPSTATE : uint8 {
	COOLING = 0,
	READY,
	PLAYERIN
};

UCLASS()
class ZOMBIEGAME_API ADeadlyPickUp : public AActor
{
	GENERATED_BODY()

public:
	////////////////////////////////////////////////
	//                 COMPONENTS                 //
	///////////////////////////////////////////////

	//mesh component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* MeshComponent;

	//the collision to see if the player is in the target area
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UShapeComponent* CollisionComponent;

public:
	UPROPERTY(EditAnywhere, Category = "Spawning")
	float CoolOffTime;

private:
	float currentCoolOfTime;

	PICKUPSTATE state;
	
public:	
	// Sets default values for this actor's properties
	ADeadlyPickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION()
		void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor);

};
