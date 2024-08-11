// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SpellSceneComponent.generated.h"

class UParticleSystemComponent;

UCLASS( ClassGroup=(HealAura), BlueprintType)
class CMP302SPELLSYSTEM_API USpellSceneComponent : public USceneComponent
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category=Heal)
	UParticleSystemComponent* Particle;
	
public:	
	// Sets default values for this component's properties
	USpellSceneComponent();

	UParticleSystemComponent* GetParticle(){return Particle;}
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	
};
