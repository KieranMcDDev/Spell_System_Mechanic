// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DataTypes.h"
#include "SpellBook.generated.h"

class AWizard;
class USpell;
UCLASS( ClassGroup=(SpellBook), BlueprintType)
class CMP302SPELLSYSTEM_API USpellBook : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpellBook();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Checks to see if current spell is valid
	bool CheckValidSpellSlot() const;
	//Used to select the current spell
	void SelectSpell(int Spell);
	//Used to cast the spell
	float CastSpell(float Mana) const;
	//Switch Target
	void NextTarget()const;
	//Set Wielder Type
	void SetWielderType(ECharacterType Type);

	USpell* GetCurrentSpell(){if(CheckValidSpellSlot()){return Spells[CurrentSpell];} return EmptySpell;};
	//GETTERS
	UFUNCTION(BlueprintCallable)
	USpell* GetBlueprintSpell(int Spell) const;
	
private:
	UPROPERTY(VisibleAnywhere, Category = SpellBook, meta = (AllowPrivateAccess = "true"))
	USpell* Spells[4];

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = SpellBook, meta = (AllowPrivateAccess = "true"))
	int CurrentSpell;

	UPROPERTY()
	USpell* EmptySpell;
	
	UPROPERTY()
	ECharacterType Wielder;
};
