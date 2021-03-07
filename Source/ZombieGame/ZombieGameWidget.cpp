// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieGameWidget.h"

#include "Components/TextBlock.h"

#include "ZombieGameCharacter.h"

bool UZombieGameWidget::Initialize() {

	const bool pInitialize = Super::Initialize();
	if (!pInitialize) { return false; }

	DeadlyTimeText = Cast<UTextBlock>(GetWidgetFromName("TextBlock_Deadly"));
	TimeAliveText = Cast<UTextBlock>(GetWidgetFromName("TextBlock_Time"));
	ZombiesKilledText = Cast<UTextBlock>(GetWidgetFromName("TextBlock_Killed"));
	GameOverText = Cast<UTextBlock>(GetWidgetFromName("TextBlock_Died"));


	return true;

}


void UZombieGameWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{

	if (DeadlyTimeText != nullptr && TimeAliveText!= nullptr && ZombiesKilledText!=nullptr) {

		APlayerController* controller = GetOwningPlayer();

		if (controller != nullptr) {

			AZombieGameCharacter* pawn = Cast<AZombieGameCharacter>(controller->GetPawn());
			if (pawn != nullptr) {

				//set deadly time left
				if (pawn->isInDeadlyState) {

					FString deadlyT = FString::Printf(TEXT("%d"), (int)pawn->currentDeadlyTime);
					DeadlyTimeText->SetText(FText::FromString(deadlyT));
				}
				else {
					DeadlyTimeText->SetText(FText::FromString(""));
				}

				//set zombies killed
				FString ZombiesCountT = FString::Printf(TEXT("%d"), pawn->ZombiesKilled);
				ZombiesKilledText->SetText(FText::FromString(ZombiesCountT));

				//set time played
				float time = pawn->timeAlive;
				FString TimeT = FString::Printf(TEXT("%2d:%2d"), (int)time/60, (int) (time - (time/60)));
				TimeAliveText->SetText(FText::FromString(TimeT));


				if (pawn->hasDied) {

					//set game Over
					GameOverText->SetText(FText::FromString("GAME OVER"));
				}

			}

		}


	}

}