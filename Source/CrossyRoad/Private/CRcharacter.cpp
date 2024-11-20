#include "CRcharacter.h"

ACRcharacter::ACRcharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	bCanLaunch = true;
}

void ACRcharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACRcharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACRcharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MoveForward", IE_Pressed, this, &ACRcharacter::LaunchForward);
	PlayerInputComponent->BindAction("MoveBackward", IE_Pressed, this, &ACRcharacter::LaunchBackward);
	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &ACRcharacter::LaunchRight);
	PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &ACRcharacter::LaunchLeft);
}

void ACRcharacter::LaunchForward()
{
	PerformLaunch(FVector(LaunchForce, 0.0f, LaunchUpwardForce));
}

void ACRcharacter::LaunchBackward()
{
	PerformLaunch(FVector(-LaunchForce, 0.0f, LaunchUpwardForce));
}

void ACRcharacter::LaunchRight()
{
	PerformLaunch(FVector(0.0f, LaunchForce, LaunchUpwardForce));
}

void ACRcharacter::LaunchLeft()
{
	PerformLaunch(FVector(0.0f, -LaunchForce, LaunchUpwardForce));
}

void ACRcharacter::ResetLaunch()
{
	bCanLaunch = true;
}

void ACRcharacter::PerformLaunch(const FVector& LaunchDirection)
{
	if (bCanLaunch)
	{
		LaunchCharacter(LaunchDirection, true, true);

		FVector HorizontalDirection = LaunchDirection;
		HorizontalDirection.Z = 0.0f;

		if (!HorizontalDirection.IsNearlyZero())
		{
			FRotator NewRotation = FRotationMatrix::MakeFromX(HorizontalDirection).Rotator();
			
			NewRotation.Yaw -= 90.0f;

			RotateSkeletalMesh(NewRotation);
		}

		bCanLaunch = false;
		
		GetWorld()->GetTimerManager().SetTimer(LaunchCooldownTimerHandle, this, &ACRcharacter::ResetLaunch, LaunchCooldown, false);
	}
}

void ACRcharacter::RotateSkeletalMesh(const FRotator& TargetRotation)
{
	USkeletalMeshComponent* SkeletalMesh = FindComponentByClass<USkeletalMeshComponent>();
	if (SkeletalMesh)
	{
		SkeletalMesh->SetWorldRotation(TargetRotation);
	}
}