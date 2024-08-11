// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CMP302SpellSystemGameMode.generated.h"

UCLASS(minimalapi)
class ACMP302SpellSystemGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACMP302SpellSystemGameMode();
	virtual void Tick(float DeltaSeconds) override;
};



