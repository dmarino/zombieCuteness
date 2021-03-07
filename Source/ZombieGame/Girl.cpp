// Fill out your copyright notice in the Description page of Project Settings.


#include "Girl.h"
#include "ZombieGameCharacter.h"
#include "GirlAIController.h"
#include "GameFramework/PlayerController.h"

#include "Components/BoxComponent.h"
// Sets default values
AGirl::AGirl()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGirl::BeginPlay()
{
	Super::BeginPlay();

	AGirlAIController* AIController = Cast<AGirlAIController>(GetController());

	if (AIController != nullptr) {

		AIController->MoveRandomLocation();
	}

}

// Called every frame
void AGirl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	AGirlAIController* AIController = Cast<AGirlAIController>(GetController());

	if (AIController != nullptr) {


		if (AIController->GetMoveStatus() != EPathFollowingStatus::Moving) {

			if (currentWaitingTime <= MaxWaitingTime) {
				currentWaitingTime += DeltaTime;
			}
			else {

				AIController->MoveRandomLocation();
				currentWaitingTime = 0;
			}


		}

		AIController->SeekPlayer();
	}


	/*AZombieGameCharacter* PlayerPawn = Cast<AZombieGameCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	if (PlayerPawn != nullptr) {

		FVector toPlayer = PlayerPawn->GetActorLocation() - GetActorLocation();
		toPlayer.Normalize();
		AddMovementInput(toPlayer, 100.0f * DeltaTime);

		FRotator ToPlayerRotation = toPlayer.Rotation();
		ToPlayerRotation.Pitch = 0.0f;
		RootComponent->SetWorldRotation(ToPlayerRotation);
	}*/

}

// Called to bind functionality to input
void AGirl::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
