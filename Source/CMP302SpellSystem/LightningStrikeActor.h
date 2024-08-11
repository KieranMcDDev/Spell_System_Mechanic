// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpellActor.h"
#include "LightningStrikeActor.generated.h"

/**
 * 
 */
class USphereComponent;
class UParticleSystemComponent;
class AMagicCharacter;

UCLASS(config=Game)
class CMP302SPELLSYSTEM_API ALightningStrikeActor : public ASpellActor
{
	GENERATED_BODY()
	UPROPERTY(VisibleDefaultsOnly, Category=LightningStrike)
	USphereComponent* LightningComp;

	UPROPERTY(VisibleDefaultsOnly, Category=LightningStrike)
	UParticleSystemComponent* LightningParticle;

public:	
	// Sets default values for this actor's properties
	ALightningStrikeActor();
	void Init(float Dam, AMagicCharacter* Targ);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float Damage;
	float Radius;
	
	AMagicCharacter* Target;
	
	//UFUNCTION()
	//void OnOverlapBegin(class  UPrimitiveComponent* OverlappedComp,class AActor* OtherActor, class  UPrimitiveComponent* Othercomp,int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//When The Fireball time runs out to something
	virtual void LifeSpanExpired() override;
};
