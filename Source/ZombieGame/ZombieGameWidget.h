// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ZombieGameWidget.generated.h"

/**
 * 
 */

class UTextBlock;

UCLASS()
class ZOMBIEGAME_API UZombieGameWidget : public UUserWidget
{
	GENERATED_BODY()

public: 

	virtual bool Initialize() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;


	UPROPERTY(Transient)
	UTextBlock* TimeAliveText;


	UPROPERTY(Transient)
	UTextBlock* ZombiesKilledText;


	UPROPERTY(Transient)
	UTextBlock* DeadlyTimeText;
	

	UPROPERTY(Transient)
	UTextBlock* GameOverText;
};
