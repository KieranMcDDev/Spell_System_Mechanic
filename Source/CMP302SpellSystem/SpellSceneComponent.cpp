// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellSceneComponent.h"
#include "Particles/ParticleSystemComponent.h"
// Sets default values for this component's properties
USpellSceneComponent::USpellSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//this->SetupAttachment(this);
	
	//Fireball Particles
	Particle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("HealAura"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem>Particles(TEXT("ParticleSystem'/Game/FXVarietyPack/Particles/P_ky_healAura.P_ky_healAura'"));
	if(Particles.Succeeded())
	{
		Particle->SetTemplate(Particles.Object);
		Particle->SetupAttachment(this);
	}
	// ...
}


// Called when the game starts
void USpellSceneComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	
	
	
}


// Called every frame
void USpellSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// ...
}

