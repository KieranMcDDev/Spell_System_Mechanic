// Copyright Epic Games, Inc. All Rights Reserved.

#include "CMP302SpellSystemGameMode.h"
#include "CMP302SpellSystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACMP302SpellSystemGameMode::ACMP302SpellSystemGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_Wizard"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ACMP302SpellSystemGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}
