// Fill out your copyright notice in the Description page of Project Settings.


#include "LightningStrike.h"
#include "Kismet/KismetSystemLibrary.h"
#include  "MagicCharacter.h"
#include "LightningStrikeActor.h"

ULightningStrike::ULightningStrike()
{
	SetDistance(100.f);
	Damage = 25.f;
	SetCooldown(0.5f);
	SetIconType(EIconType::Thunder);
	SetTargetType(ETargetType::Enemy);
}

bool ULightningStrike::CastSpell()
{
	//Super::CastSpell();
	if(GetReady() && GetValidTarget() && GetCurrentTarget()->GetCharacterType() != GetCharacterType())
	{
		ALightningStrikeActor* LightningStrikeActorActor = GetWorld()->SpawnActorDeferred<ALightningStrikeActor>(ALightningStrikeActor::StaticClass(), FTransform());
		LightningStrikeActorActor->Init(Damage, GetCurrentTarget());
		LightningStrikeActorActor->FinishSpawning(FTransform(GetPosition()));
		SetReady(false);
		return true;
	}
	return false;
}

void ULightningStrike::PrepareSpell(FVector SpellDirection, FVector SpellPosition)
{
	Super::PrepareSpell(SpellDirection, SpellPosition);
}

void ULightningStrike::NextTarget()
{
	Super::NextTarget();
}
