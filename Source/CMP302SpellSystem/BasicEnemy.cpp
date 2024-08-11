// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicEnemy.h"

#include "Spell.h"


ABasicEnemy::ABasicEnemy()
{
	//Initial Set up
	SpellBook = CreateDefaultSubobject<USpellBook>(TEXT("SpellBook"));
	SpellBook->SetupAttachment(RootComponent);
	SetCharacterType(ECharacterType::Enemy);
	SpellBook->SetWielderType(GetCharacterType());
	SpellBook->SelectSpell(2);
}

void ABasicEnemy::BeginPlay()
{
	Super::BeginPlay();
	SpellBook->SetWielderType(GetCharacterType());
}

void ABasicEnemy::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if(!SpellBook->GetCurrentSpell()->GetValidTarget())
	{
		SpellBook->NextTarget();
	}
	if(Attacking)
	{
		Attack();
	}
}

//Player Attack
void ABasicEnemy::Attack()
{
	if(SpellBook)
	{
		RemoveMana(SpellBook->CastSpell(GetMana()));
	}
}
