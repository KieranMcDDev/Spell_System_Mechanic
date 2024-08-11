// Fill out your copyright notice in the Description page of Project Settings.


#include "FireBall.h"
#include "FireBallActor.h"

UFireBall::UFireBall()
{
	//Basic Setup
	SetCooldown(0.5f);
	Damage = 35.f;
	Speed = 1000.f;
	Size = 1.f;
	ExplosionScale = 4.f;
	SetIconType(EIconType::Fire);
	SetTargetType(ETargetType::Enemy);
	SetCharacterType(ECharacterType::Ally);
}

bool UFireBall::CastSpell()
{
	//Super::CastSpell();
	
	//CHECK VALID PROJECTILE
	 //if (FireBallActorClass != nullptr)
	 {
		
	
	 	//CHECK VALID WORLD
	 	if(!GetWorld())
	 	{
	 		return false;
	 	}
	 	//IF READY CAST FIREBALL
	 	if(GetReady() == true)
	 	{
	 		SetReady(false);
	 		AFireBallActor* FireBallActor = GetWorld()->SpawnActorDeferred<AFireBallActor>(AFireBallActor::StaticClass(), FTransform(GetPosition()));
	 		FireBallActor->Init(Speed, Size, Damage, ExplosionScale,Direction, GetCharacterType());
	 		FireBallActor->FinishSpawning(FTransform(GetPosition()));
	 		return true;
	 	}
	 }
	return false;
}

void UFireBall::PrepareSpell(FVector SpellDirection, FVector SpellPosition)
{
	Direction = SpellDirection;
	SetPosition(SpellPosition);
}
