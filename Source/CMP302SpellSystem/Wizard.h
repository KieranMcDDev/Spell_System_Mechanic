// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CMP302SpellSystemCharacter.h"
#include "Wizard.generated.h"

/**
 * 
 */
class  USpellBook;
class USpellSceneComponent;
UCLASS(BlueprintType)
class CMP302SPELLSYSTEM_API AWizard : public ACMP302SpellSystemCharacter
{
	GENERATED_BODY()
public:
	//MAIN SETUPS
	AWizard();
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaSeconds) override;
	
	//FUNCTIONALITY
	//Player Attack
	void Attack();
	//Spell Slots
	void UnselectSpell();
	void SpellSlot1();
	void SpellSlot2();
	void SpellSlot3();
	void SpellSlot4();
	void NextTarget();
	//GOD MODE
	void ChangeGodMode();
private:
	
	//OBJECTS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = SpellBook, meta = (AllowPrivateAccess = "true"))
	USpellBook* SpellBook;

};

