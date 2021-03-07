// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ZombieGameGameMode.h"
#include "ZombieGameHUD.h"
#include "ZombieGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AZombieGameGameMode::AZombieGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/MyStuff/blueprints/BP_PlayerController"));

	DefaultPawnClass = PlayerPawnClassFinder.Class;
	PlayerControllerClass = PlayerControllerBPClass.Class;

	// use our custom HUD class
	HUDClass = AZombieGameHUD::StaticClass();
}
