// Fill out your copyright notice in the Description page of Project Settings.


#include "DeadlyPickUp.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

#include "ZombieGameCharacter.h"

// Sets default values
ADeadlyPickUp::ADeadlyPickUp()
{

	//creates components
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	RootComponent = CollisionComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->AttachTo(RootComponent);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADeadlyPickUp::BeginPlay()
{
	Super::BeginPlay();

	state = PICKUPSTATE::READY;

	//add dynamics on the overlap begin and end
	OnActorBeginOverlap.AddDynamic(this, &ADeadlyPickUp::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ADeadlyPickUp::OnOverlapEnd);
	
}

void ADeadlyPickUp::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	AZombieGameCharacter* player = Cast<AZombieGameCharacter>(OtherActor);
	if (player != nullptr ) {

		if (state == PICKUPSTATE::READY) {

			player->GoDeadly();
			MeshComponent->SetVisibility(false);
		}
		
		state = PICKUPSTATE::PLAYERIN;
	}

	

}

void ADeadlyPickUp::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	currentCoolOfTime = CoolOffTime;
	state = PICKUPSTATE::COOLING;

}

// Called every frame
void ADeadlyPickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (state == PICKUPSTATE::COOLING) {

		if (currentCoolOfTime > 0) {
			currentCoolOfTime -= DeltaTime;
		}
		else {
			state = PICKUPSTATE::READY;
			MeshComponent->SetVisibility(true);
		}
	}

}

