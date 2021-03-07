// Fill out your copyright notice in the Description page of Project Settings.


#include "GirlAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "ZombieGameCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

void AGirlAIController::MoveRandomLocation() {

	FVector location = FVector(FMath::RandRange(-2000,1500), FMath::RandRange(-1800, 1800),0);
	MoveToLocation(location);
}

void AGirlAIController::FollowPlayer(AActor * playerPawn) {


	if (playerPawn != nullptr) {

		MoveToLocation(playerPawn->GetActorLocation());
		SetFocus(playerPawn);

		FVector toPlayer = playerPawn->GetActorLocation() - GetPawn()->GetActorLocation();
		float distance = toPlayer.Size();

		if (distance < DistanceToPlayerTouched) {

			AZombieGameCharacter* player = Cast<AZombieGameCharacter>(playerPawn);
			if (player != nullptr) {

				player->hasDied = true;
				APlayerController* const pc = Cast<APlayerController>(player->Controller);
				if (pc != nullptr)
				{
					pc->SetPause(true);
				}
			}
		}
		
	}

}


void AGirlAIController::SeekPlayer() {

	APawn* MyPawn = GetPawn();
	AActor* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);


	if (MyPawn != nullptr && PlayerPawn != nullptr) {

		if (bSeenYou) {

			UCharacterMovementComponent* mc = Cast< UCharacterMovementComponent>(MyPawn ->GetMovementComponent());
			
			if (mc != nullptr) { mc->MaxWalkSpeed = 400; }
			FollowPlayer(PlayerPawn);
		}
		else {

			FVector myFordward = MyPawn->GetActorForwardVector();
			FVector toPlayer = PlayerPawn->GetActorLocation() - MyPawn->GetActorLocation();
			toPlayer.Normalize();

			float dotProduct = FVector::DotProduct(myFordward, toPlayer);
			float angle = FMath::RadiansToDegrees(FMath::Acos(dotProduct));

			if (dotProduct > 0.0f && angle < AngleToSeeMe) {

				FVector Start = MyPawn->GetActorLocation();
				FVector End = Start + (toPlayer *DistanceToSeeMe);
				FHitResult hit;
				FCollisionQueryParams Params(TEXT("GirlRaycast"), true, MyPawn);


				UWorld* world = GetWorld();

				if (world != nullptr) {

					const bool blockingHit = world->LineTraceSingleByChannel(hit, Start, End, ECC_Pawn, Params);
					if (blockingHit) {

						AZombieGameCharacter* playerHit = Cast<AZombieGameCharacter>(hit.Actor);
						if (playerHit != nullptr) {
							bSeenYou = true;
						}
					}
				}		
			}
		}
	}

}