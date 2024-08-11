// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetSpell.h"
#include "MagicCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

UTargetSpell::UTargetSpell()
{
	Distance = 100.f;
	Radius = 50.f;
	ValidTarget = false;
	CurrentMagicActor = nullptr;
	SetCharacterType(ECharacterType::Ally);
	
}

bool UTargetSpell::CastSpell()
{
	return Super::CastSpell();
}

void UTargetSpell::PrepareSpell(FVector SpellDirection, FVector SpellPosition)
{
	Super::PrepareSpell(SpellDirection, SpellPosition);
	const FVector Spawn = SpellPosition + SpellDirection * 400.F;
	const FVector End = SpellPosition + SpellDirection* 1000.f;
	
	const FName TraceTag("MyTraceTag");
	//GetWorld()->DebugDrawTraceTag = TraceTag;
	FCollisionQueryParams CollisionParams;
	CollisionParams.TraceTag = TraceTag;
	
	//Hit results
	TArray<FHitResult> Hit;
	//Used to check for a type of actor
	TArray<TEnumAsByte<EObjectTypeQuery>> nearbyActors;
	
	nearbyActors.Add(EObjectTypeQuery::ObjectTypeQuery7);
	
	TArray<AActor*> IgnoredActors;
	//Finds all valid characters nearby
	bool NearbyMagicCharacters = UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), Spawn, End, 400.f, nearbyActors, false, IgnoredActors, EDrawDebugTrace::ForOneFrame ,Hit, true, FLinearColor::Gray, FLinearColor::Blue, 1.f);
	
	//If character is nearby run this
	if(NearbyMagicCharacters)
	{
		TArray<AMagicCharacter*> GetAvailable;
		//Removes unavailable targets
		for(auto const Character : Hit)
		{
			//Checks to see what the correct kind of target should be
			if(GetTargetType() == ETargetType::Ally)
			{
				if(Cast<AMagicCharacter>(Character.GetActor())->GetCharacterType() != GetCharacterType())
				{
					continue;
				}
			}
			else
			{
				if(Cast<AMagicCharacter>(Character.GetActor())->GetCharacterType() == GetCharacterType())
				{
					continue;
				}
			}
			//Checks to see if the character can see the targets
			FHitResult CheckHit;
			GetWorld()->LineTraceSingleByChannel(CheckHit, Spawn - SpellDirection * 350.f, Character.GetActor()->GetActorLocation(), ECC_WorldStatic  , CollisionParams);
			if(CheckHit.IsValidBlockingHit())
			{
				if(CheckHit.GetActor() == Character.GetActor())
				{
					GetAvailable.Push(Cast<AMagicCharacter>(Character.GetActor()));
				}
			}
		}
		//Checks if there is any available targets
		if(GetAvailable.IsEmpty())
		{
			CurrentMagicActor = nullptr;
			ValidTarget = false;
			AllAvaiableTargets.Empty();
			return;
		}
		
		AllAvaiableTargets = GetAvailable;
		
		bool Check = false;
		//Checks to see if there is a current target
		for(auto Character : AllAvaiableTargets)
		{
			if(Character == CurrentMagicActor)
			{
				Check = true;
				break;
			}
		}
		//Sets current target to be the first character in the array
		if(Check == false)
		{
			CurrentMagicActor = AllAvaiableTargets[0];
		}
		//Sets valid target to true
		ValidTarget = true;
		
		//Sets the position of the target
		SetPosition(CurrentMagicActor->GetActorLocation());
		//Sets the character to be targeted for display reasons
		CurrentMagicActor->SetTargeted(true);
		CurrentMagicActor->SetCurrentTarget(true);

		//FVector SecondEnd = SecondSpawn + FVector(0,0,-1) * 1000.f;
	}
	//If there is no targets set current target to a null pointer
	else
	{
		CurrentMagicActor = nullptr;
		ValidTarget = false;
	}
	
}

void UTargetSpell::NextTarget()
{
	//Checks to see if there is any targets available
	if(AllAvaiableTargets.IsEmpty())
	{
		return;
	}

	bool Foundcurrent = false;
	//Gets the next target in the array
	for(auto const Character : AllAvaiableTargets)
	{
		//Checks to see if we have found current target
		if(Foundcurrent == true)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("START OR MIDDLE!"));
			//sets the target to be the next one in the array
			CurrentMagicActor = Character;
			return;
		}
		//Checks to see if we have found the current target in the array
		if(Character == CurrentMagicActor)
		{
			Foundcurrent = true;
		}
		//Checks to see if current target is at the end of the array
		if(Foundcurrent == true && Character == AllAvaiableTargets.Last())
		{
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("END!"));
			//sets the current target to be the start of the array
			CurrentMagicActor = AllAvaiableTargets[0];
			return;
		}
	}
}
