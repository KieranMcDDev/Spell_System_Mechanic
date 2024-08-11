// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "IceWall.generated.h"

/**
 * 
 */
UCLASS()
class CMP302SPELLSYSTEM_API UIceWall : public USpell
{
	GENERATED_BODY()
public:

	UIceWall();
	virtual bool CastSpell() override;
	virtual void PrepareSpell(FVector SpellDirection, FVector SpellPosition) override;
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = IceWall, meta = (AllowPrivateAccess = "true"))
	float Width;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = IceWall, meta = (AllowPrivateAccess = "true"))
	float Length;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = IceWall, meta = (AllowPrivateAccess = "true"))
	float Height;
	
	FVector Direction;
	bool ValidPosition;
};
