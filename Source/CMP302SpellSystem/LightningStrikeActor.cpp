// Fill out your copyright notice in the Description page of Project Settings.


#include "LightningStrikeActor.h"
#include"Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "MagicCharacter.h"
ALightningStrikeActor::ALightningStrikeActor()
{
	LightningComp = CreateDefaultSubobject<USphereComponent>(TEXT("LightningComp"));
	LightningComp->InitSphereRadius(50.0f);
	LightningComp->BodyInstance.SetCollisionProfileName("ThunderStrike");
	LightningComp->SetHiddenInGame(false);
	RootComponent = LightningComp;
	
	//LightningComp->OnComponentBeginOverlap.AddDynamic(this,  &ALightningStrikeActor::OnOverlapBegin);
	
	LightningParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("LightningParticle"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem>Particles(TEXT("ParticleSystem'/Game/FXVarietyPack/Particles/P_ky_lightning2.P_ky_lightning2'"));
	if(Particles.Succeeded())
	{
		LightningParticle->SetTemplate(Particles.Object);
		LightningParticle->SetupAttachment(RootComponent);
	}
	SetCharacterType(ECharacterType::Enemy);
	InitialLifeSpan = 0.40f;
}


void ALightningStrikeActor::Init(float Dam, AMagicCharacter* Targ)
{
	Damage = Dam;
	Target = Targ;
}

void ALightningStrikeActor::BeginPlay()
{
	Super::BeginPlay();
}

void ALightningStrikeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALightningStrikeActor::LifeSpanExpired()
{
	Super::LifeSpanExpired();
	Target->TakeDamage(Damage);
}
