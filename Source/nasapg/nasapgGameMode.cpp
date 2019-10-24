// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "nasapgGameMode.h"
#include "nasapgHUD.h"
#include "nasapgCharacter.h"
#include "UObject/ConstructorHelpers.h"

AnasapgGameMode::AnasapgGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AnasapgHUD::StaticClass();
}
