// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpellActor.h"
#include "FireBallActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UParticleSystem;

UCLASS(config=Game)
class CMP302SPELLSYSTEM_API AFireBallActor : public ASpellActor
{
	GENERATED_BODY()
	//Collision Component for the Fireball
	UPROPERTY(VisibleDefaultsOnly, Category=FireBall)
	USphereComponent* CollisionComp;
	//particle effect for fireball
	UPROPERTY(VisibleDefaultsOnly, Category=Explosion)
	UParticleSystemComponent* FireballParticle;
public:
	
	// Sets default values for this actor's properties
	AFireBallActor();
	void Init(float Sp, float Si, float damage, float explostionScale,FVector Dir, ECharacterType Type);
	//Update
	virtual void Tick(float DeltaSeconds) override;
	//Gets the Collision Component for the Fireball
	USphereComponent* GetCollisionComp()const{return CollisionComp;}

private:
	//VARIABLES
	float Size;
	float Speed;
	float Damage;
	float ExplosionScale;
	FVector Direction;
	//Functionality
	//When The Fireball time runs out to something
	virtual void LifeSpanExpired() override;
	//Collision Functionality for the fireball
	UFUNCTION()
	void OnOverlapBegin(class  UPrimitiveComponent* OverlappedComp,class AActor* OtherActor, class  UPrimitiveComponent* Othercomp,int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};

