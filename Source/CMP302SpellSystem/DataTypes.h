#pragma once
#include "DataTypes.generated.h"

UENUM()
enum class ECharacterType
{
	Empty = 0 UMETA(DisplayName="Empty"),
	Ally = 1 UMETA(DisplayName="Ally"),
	Enemy = 2 UMETA(DisplayName="Enemy")
};

UENUM()
enum class ETargetType
{
	FreeAim = 0 UMETA(DisplayName="FreeAim"),
	Ground = 1 UMETA(DisplayName="Ground"),
	Enemy = 2 UMETA(DisplayName="Enemy"),
	Ally = 3 UMETA(DisplayName="Ally")
};

UENUM(BlueprintType)
enum class EIconType : uint8
{
	Fire = 0,
	Ice = 1 ,
	Thunder = 2,
	Heal = 3,
	Nothing = 4
};
