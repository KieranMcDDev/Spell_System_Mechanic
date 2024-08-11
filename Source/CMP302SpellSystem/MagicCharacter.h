// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DataTypes.h"
#include "MagicCharacter.generated.h"



UCLASS()
class CMP302SPELLSYSTEM_API AMagicCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMagicCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//FUNCTIONALITY
	void RemoveMana(const float AmountRemoved){Mana-=AmountRemoved;}
	void TakeDamage(const float AmountReceived){Health-=AmountReceived;}
	void Heal(const float AmountHealed);
	void RestoreMana(const float AmountRestored);
	//Does something if the Chracter dies
	void Died();
	
	//SETTERS
	void SetMaxMana(const float ManaValue){MaxMana = ManaValue;}
	void SetMana(const float ManaValue){Mana = ManaValue;}
	void SetManaRegen(const float RegenValue){ManaRegen = RegenValue;}
	void SetMaxHealth(const float HealthValue){MaxHealth = HealthValue;}
	void SetHealth(const float HealthValue){Health = HealthValue;}
	void SetHealthRegen(const float RegenValue){HealthRegen = RegenValue;}
	void SetCharacterType(const ECharacterType Type){CharacterType = Type;}
	void SetTargeted(const bool targ){Targeted = targ;}
	void SetCurrentTarget(const bool targ){CurrentTarget = targ;}
	void SetGodMode(const bool mode){GodMode = mode;}
	//GETTERS
	float GetMaxMana() const {return MaxMana;}
	float GetMana() const {return Mana;}
	float GetManaRegen() const {return ManaRegen ;}
	float GetMaxHealth() const {return MaxHealth ;}
	float GetHealth() const {return Health ;}
	float GetHealthRegen() const {return HealthRegen ;}
	ECharacterType GetCharacterType() const {return CharacterType;}
	bool GetIfTargeted() const {return Targeted;}
	bool GetIfCurrentTarget() const {return CurrentTarget;}
	bool GetGodMode()const{return GodMode;}
private:
	//FUNCTIONALITY
	//Regeneration of mana and health
	void RegenMana(float DeltaSeconds);
	void RegenHealth(float DeltaSeconds);

	void CheckDied();
	//Mana Attributes For Character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float MaxMana;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float Mana;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float ManaRegen;
	//Health Attributes for character
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float MaxHealth;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float Health;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float HealthRegen;
	//What Type of Characet etc: Ally, Enemy, Player
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	ECharacterType CharacterType;
	//Keeps Track if the Character is alive
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	bool Alive;
	//Used to check if its an available target
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	bool Targeted;
	//Used to check if its currently being targeted by the player
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	bool CurrentTarget;
	
	//Used to check if its currently being targeted by the player
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	bool GodMode;
};
