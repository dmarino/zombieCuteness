// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnPoint.h"
#include "Girl.h"
#include "Engine/World.h"


// Sets default values
ASpawnPoint::ASpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	SpawnEnemy();
	
}

// Called every frame
void ASpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (currentCoolOffTime > CoolOffTime) {

		SpawnEnemy();
		currentCoolOffTime = 0;
	}
	else {
		currentCoolOffTime += DeltaTime;
	}

}

void ASpawnPoint::SpawnEnemy() {

	UWorld* World = GetWorld();

	if (World == nullptr) return;

	//set the parameters of spawning
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;

	FVector StartPosition = GetActorLocation();
	StartPosition += GetActorForwardVector() * 150.0f;
	StartPosition.Z += 40.0f;

	FRotator StartRotation = GetActorForwardVector().Rotation();

	//spawn grenade
	World->SpawnActor(Enemy, &StartPosition, &StartRotation, SpawnParameters);

}

