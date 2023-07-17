// Do not modify this file.
#include "TestingTaskTarget.h"

#include "TestingTaskGameModeBase.h"

ATestingTaskTarget::ATestingTaskTarget()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void ATestingTaskTarget::BeginPlay()
{
	Super::BeginPlay();

	if (Velocity == 0.f)
	{
		SetActorTickEnabled(false);
	}
}

int32 ATestingTaskTarget::GetScore() const
{
	return Score;
}

float ATestingTaskTarget::GetTargetVelocity() const
{
	return Velocity;
}

void ATestingTaskTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * DeltaTime * Velocity);
}

void ATestingTaskTarget::NotifyActorBeginOverlap(AActor* OtherActor)
{
	GetWorld()->GetAuthGameMode<ATestingTaskGameModeBase>()->OnTargetDestroyed(this);
	Destroy();
}

