#include "CRTreeRockSpawner.h"

ACRTreeRockSpawner::ACRTreeRockSpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetSimulatePhysics(false);
	Mesh->SetupAttachment(SceneComponent);
}

void ACRTreeRockSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACRTreeRockSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

