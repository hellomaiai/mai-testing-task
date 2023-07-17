// Do not modify this class
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TestingTaskPawnBase.generated.h"

class USplineComponent;

UCLASS()
class TESTINGTASK_API ATestingTaskPawnBase : public APawn
{
	GENERATED_BODY()

public:
	ATestingTaskPawnBase();

private:
	float Progression = -1.f;
	float ShotTimer = 2.f;

protected:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<AActor> PathActorPointer;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ProjectileActorClass;

	UPROPERTY()
	USplineComponent* PathSpline;

	virtual void BeginPlay() override;
	virtual void NotifyIsReadyToFire() {}

	bool Fire(const FVector2D& Direction);
	bool IsReadyToFire() const;

public:	
	virtual void Tick(float DeltaTime) override;
};
