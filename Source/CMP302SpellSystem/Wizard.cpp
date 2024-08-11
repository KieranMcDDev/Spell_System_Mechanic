// Fill out your copyright notice in the Description page of Project Settings.


#include "Wizard.h"
#include "SpellBook.h"

AWizard::AWizard()
{
	
	//Initial Set up
	SpellBook = CreateDefaultSubobject<USpellBook>(TEXT("SpellBook"));
	SpellBook->SetupAttachment(RootComponent);
	SetCharacterType(ECharacterType::Ally);
}


void AWizard::BeginPlay()
{
	Super::BeginPlay();
	SpellBook->SetWielderType(GetCharacterType());

}
//Input Set up
void AWizard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAction("CastSpell", IE_Pressed, this, &AWizard::Attack);
	PlayerInputComponent->BindAction("UnselectSpell", IE_Pressed, this, &AWizard::UnselectSpell);
	PlayerInputComponent->BindAction("SpellSlot1", IE_Pressed, this, &AWizard::SpellSlot1);
	PlayerInputComponent->BindAction("SpellSlot2", IE_Pressed, this, &AWizard::SpellSlot2);
	PlayerInputComponent->BindAction("SpellSlot3", IE_Pressed, this, &AWizard::SpellSlot3);
	PlayerInputComponent->BindAction("SpellSlot4", IE_Pressed, this, &AWizard::SpellSlot4);
	PlayerInputComponent->BindAction("GodMode", IE_Pressed, this, &AWizard::ChangeGodMode);
	PlayerInputComponent->BindAction("NextTarget", IE_Pressed, this, &AWizard::NextTarget);
}
//Update
void AWizard::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
//Player Attack
void AWizard::Attack()
{
	if(SpellBook)
	{
		RemoveMana(SpellBook->CastSpell(GetMana()));
	}
}

//SELECTS SPELL
void AWizard::UnselectSpell()
{
	SpellBook->SelectSpell(-1);
}
void AWizard::SpellSlot1() 
{
	SpellBook->SelectSpell(0);
}
void AWizard::SpellSlot2() 
{
	SpellBook->SelectSpell(1);
}
void AWizard::SpellSlot3() 
{
	SpellBook->SelectSpell(2);
}

void AWizard::SpellSlot4()
{
	SpellBook->SelectSpell(3);
}

void AWizard::NextTarget()
{
	SpellBook->NextTarget();
}

void AWizard::ChangeGodMode()
{
	
	if(!GetGodMode())
	{
		SetGodMode(true);
		SetMaxHealth(999999);
		SetHealth(999999);
		SetHealthRegen(999999);
		SetMaxMana(999999);
		SetMana(999999);
		SetManaRegen(999999);
	}
	else
	{
		SetGodMode(false);
		SetMaxHealth(100.f);
		SetHealth(100.f);
		SetHealthRegen(10.f);
		SetMaxMana(1000.f);
		SetMana(1000.f);
		SetManaRegen(50.f);
	}
}
