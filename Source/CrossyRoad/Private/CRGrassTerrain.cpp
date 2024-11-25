#include "CRGrassTerrain.h"


ACRGrassTerrain::ACRGrassTerrain()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetSimulatePhysics(false);
	Mesh->SetupAttachment(SceneComponent);

	Start = CreateDefaultSubobject<UStaticMeshComponent>("Start");
	Start->SetSimulatePhysics(false);
	Start->SetupAttachment(SceneComponent);

	End = CreateDefaultSubobject<UStaticMeshComponent>("End");
	End->SetSimulatePhysics(false);
	End->SetupAttachment(SceneComponent);
}

void ACRGrassTerrain::BeginPlay()
{
	Super::BeginPlay();

	FVector StartWorldLocation = Start->GetComponentLocation();
	FVector EndWorldLocation = End->GetComponentLocation();
	
}

void ACRGrassTerrain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

