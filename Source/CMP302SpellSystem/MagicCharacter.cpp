// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicCharacter.h"

// Sets default values
AMagicCharacter::AMagicCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MaxMana = 1000.f;
	Mana = MaxMana;
	ManaRegen = 50.f;
	MaxHealth = 100.f;
	Health = MaxHealth;
	HealthRegen = 10.f;
	CharacterType = ECharacterType::Enemy;
	Alive = true;
	Targeted = false;
	GodMode = false;
}

// Called when the game starts or when spawned
void AMagicCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMagicCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CheckDied();
	Died();
	//Died();
	RegenMana(DeltaTime);
	RegenHealth(DeltaTime);
	Targeted = false;
	CurrentTarget = false;
}

//Restores Health
void AMagicCharacter::Heal(const float AmountHealed)
{
	if(Health < MaxHealth)
	{
		Health += AmountHealed;
	}
	else if(Health > MaxHealth)
	{
		Health = MaxHealth;
	}
}
//Restores Mana
void AMagicCharacter::RestoreMana(const float AmountRestored)
{
	if(Mana < MaxMana)
	{
		Mana +=AmountRestored;
	}
	else if(Mana > MaxMana)
	{
		Mana = MaxMana;
	}
}
//Functionality for killing the player
void AMagicCharacter::Died()
{
	if(!Alive)Destroy();
}

//Regen Mana
void AMagicCharacter::RegenMana(const float DeltaSeconds)
{
	RestoreMana(ManaRegen * DeltaSeconds);
}

void AMagicCharacter::RegenHealth(const float DeltaSeconds)
{
	Heal(HealthRegen * DeltaSeconds);
}

void AMagicCharacter::CheckDied()
{
	if(Health>0 || GodMode == true)
	{
		return;
	}
	Alive = false;
}
