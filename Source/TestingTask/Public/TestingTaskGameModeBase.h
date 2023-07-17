#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TestingTaskGameModeBase.generated.h"

class ATestingTaskTarget;
class UNiagaraSystem;

/*
 * Use this class as a starting point for your Scoreboard UI.
 */
UCLASS()
class TESTINGTASK_API ATestingTaskGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UNiagaraSystem> TargetDestroyedParticlesPointer;

	UPROPERTY()
	UNiagaraSystem* TargetDestroyedParticles;

	UFUNCTION()
	void DrawScore();

public:
	int32 Score;
	int32 ShotsFired;
	int32 TargetsDestroyed;

	float GetTotalScore() const;
	void OnGameFinished();
	void OnTargetDestroyed(ATestingTaskTarget* Target);
	virtual void StartPlay() override;
};
