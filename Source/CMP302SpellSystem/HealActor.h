// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpellActor.h"
#include "HealActor.generated.h"

/**
 * 
 */

class UParticleSystem;
class AMagicCharacter;
UCLASS(config=Game)
class CMP302SPELLSYSTEM_API AHealActor : public ASpellActor
{
	GENERATED_BODY()
	
	//particle effect for fireball
	UPROPERTY(VisibleDefaultsOnly, Category=HealAura)
	UParticleSystemComponent* HealParticles;
public:
	
	// Sets default values for this actor's properties
	AHealActor();
	void Init(AMagicCharacter* Target, float Heal);
	//Update
	virtual void Tick(float DeltaSeconds) override;
	
private:
	
	AMagicCharacter* Target;

	float HealAmount;

	//When The Fireball time runs out to something
	virtual void LifeSpanExpired() override;
};



