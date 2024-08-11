// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TargetSpell.h"
#include "Heal.generated.h"

/**
 * 
 */
class UParticleSystem;
UCLASS()
class CMP302SPELLSYSTEM_API UHeal : public UTargetSpell
{
	GENERATED_BODY()

public:
	UHeal();
	virtual bool CastSpell() override;
	virtual void PrepareSpell(FVector SpellDirection, FVector SpellPosition) override;
	virtual void NextTarget() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = IceWall, meta = (AllowPrivateAccess = "true"))
	float HealAmount;
	
	
};
