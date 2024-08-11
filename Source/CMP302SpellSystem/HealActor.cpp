// Fill out your copyright notice in the Description page of Project Settings.


#include "HealActor.h"

#include "MagicCharacter.h"
#include "Particles/ParticleSystemComponent.h"
AHealActor::AHealActor()
{
	//Fireball Particles
	HealParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("HealAuraParticles"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem>Particles(TEXT("ParticleSystem'/Game/ThirdPerson/Blueprints/P_ky_healAura.P_ky_healAura'"));
	if(Particles.Succeeded())
	{
		HealParticles->SetTemplate(Particles.Object);
		HealParticles->SetupAttachment(RootComponent);
	}
	InitialLifeSpan = 5.f;
}

void AHealActor::Init(AMagicCharacter* Tar, float Heal)
{
	Target = Tar;
	HealAmount = Heal;
}


void AHealActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	Target->Heal(DeltaSeconds * HealAmount);
}

void AHealActor::LifeSpanExpired()
{
	Super::LifeSpanExpired();
}