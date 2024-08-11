// Fill out your copyright notice in the Description page of Project Settings.


#include "Heal.h"
#include "MagicCharacter.h"
#include "HealActor.h"

UHeal::UHeal()
{
	HealAmount = 10.f;
	SetIconType(EIconType::Heal);
	SetTargetType(ETargetType::Ally);
	SetCharacterType(ECharacterType::Ally);
	
}

bool UHeal::CastSpell()
{
	//return Super::CastSpell();
	if(GetReady() && GetValidTarget() && GetCurrentTarget()->GetCharacterType() == GetCharacterType())
	{
		//Spawns and attaches healing actor to target
		AHealActor* HealActor = GetWorld()->SpawnActorDeferred<AHealActor>(AHealActor::StaticClass(), FTransform(FVector(0)));
		HealActor->AttachToActor(GetCurrentTarget(), FAttachmentTransformRules::SnapToTargetIncludingScale);
		HealActor->Init(GetCurrentTarget(), HealAmount);
		HealActor->FinishSpawning(FTransform(FVector(0)));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));		SetReady(false);
		return true;
	}
	return false;
}

void UHeal::PrepareSpell(FVector SpellDirection, FVector SpellPosition)
{
	Super::PrepareSpell(SpellDirection, SpellPosition);
}

void UHeal::NextTarget()
{
	Super::NextTarget();
}
