#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CRTreeRockSpawner.generated.h"

class USceneComponent;
class UStaticMeshComponent;

UCLASS()
class CROSSYROAD_API ACRTreeRockSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ACRTreeRockSpawner();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<USceneComponent> SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Mesh;
};
