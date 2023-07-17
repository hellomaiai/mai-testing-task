// Do not modify this file.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestingTaskProjectile.generated.h"

UCLASS()
class TESTINGTASK_API ATestingTaskProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestingTaskProjectile();

protected:
	UPROPERTY(EditAnywhere)
	float Lifetime = 8.f;

	UPROPERTY(EditAnywhere)
	float Velocity = 1.f;

public:	
	float GetProjectileVelocity() const;
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
