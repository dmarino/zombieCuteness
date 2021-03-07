// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZombieGameProjectile.h"
#include "DeadlyProjectile.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIEGAME_API ADeadlyProjectile : public AZombieGameProjectile
{
	GENERATED_BODY()

public:

	ADeadlyProjectile();

	virtual void doExtra(AActor* OtherActor) override;
	
};
