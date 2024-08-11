// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosionActor.h"

#include "MagicCharacter.h"
#include"Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AExplosionActor::AExplosionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("ExplosionComp"));
	CollisionComponent->InitSphereRadius(50.0f);
	CollisionComponent->BodyInstance.SetCollisionProfileName("Explosion");
	CollisionComponent->SetHiddenInGame(false);
	
	RootComponent = CollisionComponent;
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this,  &AExplosionActor::OnOverlapBegin);
	
	ExplosionParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ExplosionParticle"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem>Particles(TEXT("ParticleSystem'/Game/ThirdPerson/Blueprints/P_ky_explosion.P_ky_explosion'"));
	if(Particles.Succeeded())
	{
		ExplosionParticle->SetTemplate(Particles.Object);
		ExplosionParticle->SetupAttachment(RootComponent);
	}
	SetCharacterType(ECharacterType::Enemy);
	InitialLifeSpan = 0.5f;
}

void AExplosionActor::Init(float Dam, float Rad, ECharacterType Type)
{
	Damage = Dam;
	Radius = Rad;
	CollisionComponent->SetSphereRadius(Radius);
	ExplosionParticle->SetRelativeScale3D(FVector(Radius/250));
	SetCharacterType(Type);
}

// Called when the game starts or when spawned
void AExplosionActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExplosionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AExplosionActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* Othercomp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FVector PushDirection = OverlappedComp->GetComponentLocation() - OtherActor->GetActorLocation();
	AMagicCharacter* Character = dynamic_cast<AMagicCharacter*>(OtherActor);
	if(Character)
	{
		if(Character->GetCharacterType() != GetCharacterType())
		{
			FHitResult CheckHit;
			FVector Spawn = GetActorLocation();
			const FName TraceTag("MyTraceTag");
			//GetWorld()->DebugDrawTraceTag = TraceTag;
			FCollisionQueryParams CollisionParams;
			CollisionParams.TraceTag = TraceTag;
			GetWorld()->LineTraceSingleByChannel(CheckHit, Spawn, Character->GetActorLocation(), ECC_WorldStatic  , CollisionParams);
			if(CheckHit.GetActor() == OtherActor)
			{
				PushDirection.Normalize();
				Character->GetCharacterMovement()->AddForce(-PushDirection * 5000000);
				Character->TakeDamage(Damage/2.f);
			}
		;
			return;
		}
	}
	
	UMeshComponent* Mesh = dynamic_cast<UMeshComponent*>(Othercomp);
	if(Mesh)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("START OR MIDDLE!"));	
		PushDirection.Normalize();
		Mesh->AddForce(-PushDirection * 5000000);
		return;
	}
}



