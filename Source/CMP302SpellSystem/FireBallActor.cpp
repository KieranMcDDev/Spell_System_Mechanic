// Fill out your copyright notice in the Description page of Project Settings.


#include "FireBallActor.h"
#include "MagicCharacter.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "ExplosionActor.h"


// Sets default values
AFireBallActor::AFireBallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Fireball Collision
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(50.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("FireBall");
	CollisionComp->SetHiddenInGame(false);
	
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;
	RootComponent = CollisionComp;
	//CollisionComp->SetCollisionObjectType(ECC_WorldStatic);
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this,  &AFireBallActor::OnOverlapBegin);
	
	InitialLifeSpan = 3;
	
	//Fireball Particles
	FireballParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ExplosionParticle"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem>Particles(TEXT("ParticleSystem'/Game/ThirdPerson/Blueprints/P_ky_fireBall'"));
	if(Particles.Succeeded())
	{
		FireballParticle->SetTemplate(Particles.Object);
		FireballParticle->SetupAttachment(RootComponent);
	}
}

void AFireBallActor::Init(float Sp, float Si,float Da, float explosionScale,FVector Dir, ECharacterType Type)
{
	Speed = Sp;
	Size = Si;
	Damage = Da;
	ExplosionScale = explosionScale;
	CollisionComp->SetWorldScale3D(FVector(Size));
	Direction = Dir;
	SetCharacterType(Type);
}

void AFireBallActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	CollisionComp->MoveComponent(Direction * Speed * DeltaSeconds, FRotator(0), false);
}

void AFireBallActor::LifeSpanExpired()
{
	Super::LifeSpanExpired();
	AExplosionActor* ExplosionActor = GetWorld()->SpawnActorDeferred<AExplosionActor>(AExplosionActor::StaticClass(), FTransform(GetActorLocation()));
	ExplosionActor->Init(Damage,  CollisionComp->GetScaledSphereRadius() * ExplosionScale, GetCharacterType());
	ExplosionActor->FinishSpawning(FTransform(GetActorLocation()));

}

void AFireBallActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	AMagicCharacter* Character= dynamic_cast<AMagicCharacter*>(OtherActor);;
	if(Character)
	{
		if(Character->GetCharacterType() == GetCharacterType())
		{
			return;
		}

		Character->TakeDamage(Damage);
	}
	Destroy();
	
	//Disable Collision So explosion doesnt collide with it
	AExplosionActor* ExplosionActor = GetWorld()->SpawnActorDeferred<AExplosionActor>(AExplosionActor::StaticClass(), FTransform(GetActorLocation()));
	ExplosionActor->Init(Damage,  CollisionComp->GetScaledSphereRadius() * ExplosionScale + 50.F,GetCharacterType());
	ExplosionActor->FinishSpawning(FTransform(GetActorLocation()));
	
}

