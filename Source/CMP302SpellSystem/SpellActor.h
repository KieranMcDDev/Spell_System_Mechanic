// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataTypes.h"
#include "SpellActor.generated.h"

UCLASS()
class CMP302SPELLSYSTEM_API ASpellActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpellActor();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void SetCharacterType(const ECharacterType Type){CharacterType = Type;}
	ECharacterType GetCharacterType() const {return CharacterType;}
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//Used to see who cast the spell
	ECharacterType CharacterType;
};
