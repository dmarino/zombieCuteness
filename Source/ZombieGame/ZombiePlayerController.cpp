// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombiePlayerController.h"
#include "ZombieGameWidget.h"

void AZombiePlayerController::BeginPlay() {

	Super::BeginPlay();

	if (GameWidgetBP != nullptr && IsLocalController()) {
		GameWidget = CreateWidget<UZombieGameWidget>(this, GameWidgetBP);

		if (GameWidget != nullptr) {
			GameWidget->AddToViewport();
		}

	}
}