// Fill out your copyright notice in the Description page of Project Settings.


#include "DeadlyProjectile.h"
#include "Girl.h"
#include "ZombieGameCharacter.h"
#include "Kismet/GameplayStatics.h"


ADeadlyProjectile::ADeadlyProjectile() {


}


void ADeadlyProjectile::doExtra(AActor* OtherActor) {

	AGirl* girl = Cast<AGirl>(OtherActor);

	if (girl != nullptr) {

		AZombieGameCharacter* PlayerPawn = Cast<AZombieGameCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

		if (PlayerPawn != nullptr) {

			PlayerPawn->ZombiesKilled++;
		}

		girl->Destroy();
	}
}