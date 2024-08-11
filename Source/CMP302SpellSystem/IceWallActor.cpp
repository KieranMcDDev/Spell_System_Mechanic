// Fill out your copyright notice in the Description page of Project Settings.


#include "IceWallActor.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
AIceWallActor::AIceWallActor()
{
	PrimaryActorTick.bCanEverTick = true;
	//Ice Wall Collision
	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CubeComp"));
	CollisionComp->BodyInstance.SetCollisionProfileName("IceWall");
	CollisionComp->SetHiddenInGame(false);
	
	RootComponent = CollisionComp;
	CollisionComp->SetCollisionObjectType(ECC_WorldStatic);
	
	InitialLifeSpan = 10;
	//Fireball Mesh
	this->CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	this->CubeMesh->SetupAttachment(RootComponent);
	this->CubeMesh->SetCollisionProfileName("Default");
	static ConstructorHelpers::FObjectFinder<UStaticMesh>CubeMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if(CubeMeshAsset.Succeeded() != NULL)
	{
		this->CubeMesh->SetStaticMesh(CubeMeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial>IceMaterial(TEXT("Material'/Game/ThirdPerson/Blueprints/NewMaterial.NewMaterial'"));
	if(IceMaterial.Succeeded())
	{
		this->CubeMesh->SetMaterial(0, IceMaterial.Object);
	}
}

void AIceWallActor::Init(FVector Dir,float Length, float Width, float Height)
{
	CollisionComp->SetWorldRotation(Dir.Rotation());
	CollisionComp->SetRelativeScale3D(FVector(Length,Width,Height));
}

void AIceWallActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
