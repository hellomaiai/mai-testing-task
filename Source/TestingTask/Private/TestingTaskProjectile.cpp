// Do not modify this file.

#include "TestingTaskProjectile.h"

// Sets default values
ATestingTaskProjectile::ATestingTaskProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

// Called every frame
void ATestingTaskProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + GetActorForwardVector() * DeltaTime * Velocity);

	if (Lifetime <= 0.f)
	{
		Destroy();
	}

	Lifetime -= DeltaTime;
}

void ATestingTaskProjectile::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Destroy();
}

float ATestingTaskProjectile::GetProjectileVelocity() const
{
	return Velocity;
}

