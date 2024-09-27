// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tp_WorkSpaceGameMode.h"
#include "Tp_WorkSpaceCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATp_WorkSpaceGameMode::ATp_WorkSpaceGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
