// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GirlAIController.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIEGAME_API AGirlAIController : public AAIController
{
	GENERATED_BODY()

public:

	void FollowPlayer(AActor * player);
	void SeekPlayer();

	void MoveRandomLocation();

	

	UPROPERTY()
	bool bSeenYou;

	UPROPERTY(EditAnywhere, Category = "seek")
	float AngleToSeeMe;

	UPROPERTY(EditAnywhere, Category = "seek")
	float DistanceToSeeMe;

	UPROPERTY(EditAnywhere, Category = "seek")
	float DistanceToPlayerTouched;
};
