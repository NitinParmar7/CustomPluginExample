// Copyright Epic Games, Inc. All Rights Reserved.

#include "SettingsPluginSampleGameMode.h"
#include "SettingsPluginSampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASettingsPluginSampleGameMode::ASettingsPluginSampleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
