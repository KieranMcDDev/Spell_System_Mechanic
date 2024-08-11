// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell.h"

// Sets default values for this component's properties
USpell::USpell()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Ready = true;
	Timer = 0.f;
	Cooldown = 1.f;
	Mana = 100;
	Position = FVector(0);
	TargetType = ETargetType::FreeAim;
	IconType = EIconType::Nothing;
	CharacterType = ECharacterType::Enemy;
	// ...
}


// Called when the game starts
void USpell::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

bool USpell::CastSpell()
{
	if(Ready == true)
	{
		Ready = false;
		return true;
	}
	return false;
}

void USpell::ApplyCooldown(float DeltaTime)
{
	if(Ready == true)
	{
		return;
	}
	if(Timer < Cooldown)
	{
		Timer += DeltaTime;
	}
	else
	{
		Ready = true;
		Timer = 0;
	}
}


// Called every frame
void USpell::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	ApplyCooldown(DeltaTime);
	// ...
}

