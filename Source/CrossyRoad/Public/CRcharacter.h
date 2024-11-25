#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CRcharacter.generated.h"

UCLASS()
class CROSSYROAD_API ACRcharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACRcharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void LaunchForward();

	void LaunchBackward();

	void LaunchRight();

	void LaunchLeft();

private:
	void ResetLaunch();

	void PerformLaunch(const FVector& LaunchDirection);
	
	void RotateSkeletalMesh(const FRotator& TargetRotation);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float LaunchForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float LaunchUpwardForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cooldown")
	float LaunchCooldown;

private:
	bool bCanLaunch;

	FTimerHandle LaunchCooldownTimerHandle;

	float RotationInterpSpeed;
};
