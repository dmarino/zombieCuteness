// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ZombiePlayerController.generated.h"

/**
 * 
 */

class UZombieGameWidget;
UCLASS()
class ZOMBIEGAME_API AZombiePlayerController : public APlayerController
{
	GENERATED_BODY()

		virtual void BeginPlay() override;

	UPROPERTY(Transient)
	UZombieGameWidget* GameWidget;

	UPROPERTY(EditDefaultsOnly, Category = HUD)
	TSubclassOf<UZombieGameWidget> GameWidgetBP;
	
};
