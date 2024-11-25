#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CRGrassTerrain.generated.h"

class USceneComponent;
class UStaticMeshComponent;

UCLASS()
class CROSSYROAD_API ACRGrassTerrain : public AActor
{
	GENERATED_BODY()
	
public:	
	ACRGrassTerrain();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<USceneComponent> SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Start;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UStaticMeshComponent> End;
	
};
