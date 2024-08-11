// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellBook.h"
#include "FireBall.h"
#include "IceWall.h"
#include "LightningStrike.h"
#include "Heal.h"
// Sets default values for this component's properties
USpellBook::USpellBook()
{
	PrimaryComponentTick.bCanEverTick = true;
	EmptySpell = CreateDefaultSubobject<USpell>(TEXT("Empty"));
	
	Spells[0] = CreateDefaultSubobject<UFireBall>("FireBall");
	Spells[1] = CreateDefaultSubobject<UIceWall>("IceWall");
	Spells[2] = CreateDefaultSubobject<ULightningStrike>("LightningStrike");
	Spells[3] =CreateDefaultSubobject<UHeal>("Heal");
	CurrentSpell = 2;
}


// Called when the game starts
void USpellBook::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
	
}

// Called every frame
void USpellBook::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(CheckValidSpellSlot())
	{
		Spells[CurrentSpell]->PrepareSpell(this->GetForwardVector(), FVector(GetComponentToWorld().GetLocation() + this->GetForwardVector()));
	}
	// ...
}

bool USpellBook::CheckValidSpellSlot() const
{
	if(CurrentSpell > 3 || CurrentSpell < 0)
	{
		return false;
	}
	return true;
}

void USpellBook::SelectSpell(int Spell)
{
	CurrentSpell = Spell;
}

float USpellBook::CastSpell(float Mana) const
{
	if(!CheckValidSpellSlot())
	{
		return 0;
	}
	
	if(Spells[CurrentSpell]->GetMana() < Mana)
	{
		if(Spells[CurrentSpell]->CastSpell())
		{
			return Spells[CurrentSpell]->GetMana();
		}
		return 0;
	}
	return 0;
}

void USpellBook::NextTarget() const
{
	if(!CheckValidSpellSlot())
	{
		return;
	}
	
	Spells[CurrentSpell]->NextTarget();
}

void USpellBook::SetWielderType(ECharacterType Type)
{
	Wielder = Type;
	for(int i = 0; i < 4; i ++)
	{
		Spells[i]->SetCharacterType(Wielder);
	}
}

USpell* USpellBook::GetBlueprintSpell(const int Spell) const
{
	if(CheckValidSpellSlot())
	{
		return Spells[Spell];
	}
	
	return EmptySpell;
}


