// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnPoint.generated.h"


class AGirl;

UCLASS()
class ZOMBIEGAME_API ASpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnEnemy();

public:

	UPROPERTY(EditAnywhere, Category = "spawn")
		float CoolOffTime;

	UPROPERTY(EditAnywhere, Category = "spawn")
		TSubclassOf<AGirl> Enemy;


private:

	float currentCoolOffTime;

};
