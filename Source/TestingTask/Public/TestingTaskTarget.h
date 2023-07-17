// Do not modify this file.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestingTaskTarget.generated.h"

UCLASS()
class TESTINGTASK_API ATestingTaskTarget : public AActor
{
	GENERATED_BODY()
	
public:	
	ATestingTaskTarget();

protected:
	UPROPERTY(EditAnywhere)
	int32 Score;

	UPROPERTY(EditAnywhere)
	float Velocity;

	virtual void BeginPlay() override;

public:	
	float GetTargetVelocity() const;
	int32 GetScore() const;
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
