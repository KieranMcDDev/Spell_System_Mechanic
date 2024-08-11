// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MagicCharacter.h"
#include "SpellBook.h"
#include "BasicEnemy.generated.h"

/**
 * 
 */
class ASpellBook;

UCLASS()
class CMP302SPELLSYSTEM_API ABasicEnemy : public AMagicCharacter
{
	GENERATED_BODY()
public:
	//MAIN SETUPS
	ABasicEnemy();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	//Enemy Attack
	void Attack();
private:

	//OBJECTS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = SpellBook, meta = (AllowPrivateAccess = "true"))
	USpellBook* SpellBook;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SpellBook, meta = (AllowPrivateAccess = "true"))
	bool Attacking;
};
