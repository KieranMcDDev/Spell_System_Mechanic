// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "FireBall.generated.h"

/**
 * 
 */
UCLASS()
class CMP302SPELLSYSTEM_API UFireBall : public USpell
{
	GENERATED_BODY()
public:

	//PROJECTILE OF FIRE BALL
	UPROPERTY(EditDefaultsOnly, Category=FireBall)
	TSubclassOf<class AFireBallActor> FireBallActorClass;
	
	UFireBall();

	//FUNCTIONALITY
	virtual bool CastSpell() override;
	virtual void PrepareSpell(FVector SpellDirection, FVector SpellPosition) override;
	
	//SETTERS
	void SetDamage(const float D){Damage = D;}
	void SetSpeed(const float S){Speed = S;}
	void SetSize(const float S){Speed = S;}

	
	
protected:
	
private:
	//VARIABLES
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = FireBall, meta = (AllowPrivateAccess = "true"))
	float Damage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = FireBall, meta = (AllowPrivateAccess = "true"))
	float ExplosionScale;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = FireBall, meta = (AllowPrivateAccess = "true"))
	float Speed;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = FireBall, meta = (AllowPrivateAccess = "true"))
	float Size;

	FVector Direction;
	
};
