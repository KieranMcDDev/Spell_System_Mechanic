// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellActor.h"

#include "MagicCharacter.h"

// Sets default values
ASpellActor::ASpellActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CharacterType = ECharacterType::Enemy;
}

// Called when the game starts or when spawned
void ASpellActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpellActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

