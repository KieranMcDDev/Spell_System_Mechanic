// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpellActor.h"
#include "ExplosionActor.generated.h"

class USphereComponent;
class UParticleSystem;

UCLASS(config=Game)
class CMP302SPELLSYSTEM_API AExplosionActor : public ASpellActor
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleDefaultsOnly, Category=Explosion)
	USphereComponent* CollisionComponent;

	UPROPERTY(VisibleDefaultsOnly, Category=Explosion)
	UParticleSystemComponent* ExplosionParticle;
	
public:	
	// Sets default values for this actor's properties
	AExplosionActor();
	void Init(float Dam, float Rad, ECharacterType Type);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float Damage;
	float Radius;
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,  UPrimitiveComponent* Othercomp,int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	
};
