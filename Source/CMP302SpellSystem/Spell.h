// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DataTypes.h"
#include "Spell.generated.h"



UCLASS( ClassGroup=(Custom),BlueprintType )
class CMP302SPELLSYSTEM_API USpell : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpell();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	//SPELL CONTROLS
	//Casts the spell
	virtual bool CastSpell();
	//Prepare the spell before cast
	virtual void PrepareSpell(){};
	virtual void PrepareSpell(FVector SpellDirection, FVector SpellPosition){};
	//Used to switch target: Note: Not all spells use a target
	virtual void NextTarget(){};
	//gets if the target is valid
	virtual bool GetValidTarget() {return true;};
	//Updates the cooldown
	void ApplyCooldown(float DeltaTime);
	
	//SETTERS
	void SetMana(float const M){Mana = M;}
	void SetCooldown(float const C){Cooldown = C;}
	void SetReady(bool const R){Ready = R;}
	void SetPosition(const FVector Pos){Position = Pos;}
	void SetTargetType(const ETargetType Type){TargetType = Type;};
	void SetIconType(const EIconType Type){IconType = Type;};
	void SetCharacterType(const ECharacterType Type){CharacterType = Type;};
	//GETTERS
	float GetMana() const {return Mana;}
	float GetCooldown() const {return Cooldown;} 
	float GetCooldownTimer() const { return Timer; }
	bool GetReady() const {return Ready;}
	FVector GetPosition() const {return Position;}
	ETargetType GetTargetType() const{return TargetType;};
	ECharacterType GetCharacterType() const {return CharacterType;}
	
private:
	//Cost of the spell to ues
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float Mana;
	//How long the spell takes to be usable
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float Cooldown;
	//Timer used for cooldown
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float Timer;
	//Ready to Cast Spell
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool Ready;
	//Ready to Cast Spell
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FVector Position;
	//How the spell is aimed
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	ETargetType TargetType;
	//Icon Type for UI
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	EIconType IconType;
	//The Type Of Caster of the Spell
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	ECharacterType CharacterType;
};
