// Fill out your copyright notice in the Description page of Project Settings.


#include "IceWall.h"
#include "IceWallActor.h"

UIceWall::UIceWall()
{
	Length = 1.f;
	Width = 10.f;
	Height = 4.f;
	SetCooldown(15.f);
	SetTargetType(ETargetType::Ground);
	SetIconType(EIconType::Ice);
	ValidPosition = false;
}

bool UIceWall::CastSpell()
{
	//Super::CastSpell();
	if(GetReady() == true && ValidPosition == true)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("IceWall Length: %f"), Length));
		SetReady(false);
		AIceWallActor* IceWallActor = GetWorld()->SpawnActorDeferred<AIceWallActor>(AIceWallActor::StaticClass(), FTransform(GetPosition()));
		IceWallActor->Init(Direction, Length, Width, Height);
		IceWallActor->FinishSpawning(FTransform(GetPosition()));
		return true;
	}
	return false;
}

void UIceWall::PrepareSpell(FVector SpellDirection, FVector SpellPosition)
{
	Direction = SpellDirection;

	FHitResult Hit;
	FVector FirstSpawn = SpellPosition+ SpellDirection * 50.f;
	FVector FirstEnd = FirstSpawn + SpellDirection * 1000.f;
	
	const FName TraceTag("MyTraceTag");
	//GetWorld()->DebugDrawTraceTag = TraceTag;
	FCollisionQueryParams CollisionParams;
	CollisionParams.TraceTag = TraceTag;
	
	
	GetWorld()->LineTraceSingleByChannel(Hit, FirstSpawn, FirstEnd, ECC_WorldStatic, CollisionParams);
	
	if(Hit.HasValidHitObjectHandle())
	{
		FVector SecondSpawn = Hit.Location;
		FVector SecondEnd = SecondSpawn + FVector(0,0,-1) * 1000.f;
		GetWorld()->LineTraceSingleByChannel(Hit, SecondSpawn, SecondEnd, ECC_WorldStatic, CollisionParams);
		SetPosition(Hit.Location);
	}
	else
	{
		FVector SecondSpawn = SpellPosition+ SpellDirection * 1000.f;
		FVector SecondEnd = SecondSpawn + FVector(0,0,-1) * 1000.f;
		GetWorld()->LineTraceSingleByChannel(Hit, SecondSpawn, SecondEnd, ECC_WorldStatic, CollisionParams);
		SetPosition(Hit.Location);
	}

	if(Hit.HasValidHitObjectHandle())
	{
		ValidPosition = true;
	}
	else
	{
		ValidPosition = false;
	}
}

