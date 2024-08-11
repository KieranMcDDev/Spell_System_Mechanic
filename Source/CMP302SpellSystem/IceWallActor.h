// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpellActor.h"
#include "IceWallActor.generated.h"

/**
 * 
 */
class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class CMP302SPELLSYSTEM_API AIceWallActor : public ASpellActor
{
	GENERATED_BODY()
	//Collision Component for the Fireball
	UPROPERTY(VisibleDefaultsOnly, Category=FireBall)
	UBoxComponent* CollisionComp;
	//Mesh For the Fireball
	UPROPERTY(VisibleDefaultsOnly, Category=IceWall)
	UStaticMeshComponent* CubeMesh;
	
public:

	// Sets default values for this actor's properties
	AIceWallActor();
	void Init(FVector Dir, float Length, float Width, float Height);
	
	//Update
	virtual void Tick(float DeltaSeconds) override;
	//Gets the Collision Component for the IceWall
	UBoxComponent* GetCollisionComp()const{return CollisionComp;}
	
private:
	
};
