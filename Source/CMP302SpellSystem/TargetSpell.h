// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "TargetSpell.generated.h"

/**
 * 
 */
class AMagicCharacter;
UCLASS()
class CMP302SPELLSYSTEM_API UTargetSpell : public USpell
{
	GENERATED_BODY()
public:
	UTargetSpell();
	virtual bool CastSpell() override;
	virtual void PrepareSpell(FVector SpellDirection, FVector SpellPosition) override;
	virtual void NextTarget() override;
	virtual bool GetValidTarget() override {return ValidTarget;}
	//Setters
	void SetDistance(float Dist){Distance = Dist;}
	void SetRadius(float Rad){Radius = Rad;}
	//Getters
	float GetDistance() const {return Distance;}
	float GetRadius() const {return Radius;}

	AMagicCharacter* GetCurrentTarget() const {return CurrentMagicActor;}
private:

	//Used to see how far the sphere trace will go
	float Distance;
	//Used for the size of the sphere mesh
	float Radius;
	
	//Used to check if an available target
	bool ValidTarget;

	//Used to see all avaiable targets
	TArray<AMagicCharacter*> AllAvaiableTargets;
	//Used to store list of targetable characters
	AMagicCharacter* CurrentMagicActor;
};
