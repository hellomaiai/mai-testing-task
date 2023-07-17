#include "TestingTaskGameModeBase.h"

#include "TestingTaskTarget.h"
#include "NiagaraFunctionLibrary.h"

void ATestingTaskGameModeBase::DrawScore()
{
	const float Accuracy = ((TargetsDestroyed + 1.f) / (ShotsFired + 1.f)) * 100.f;
	FString Message;
	Message.Appendf(TEXT("Score: %i\n"), Score);
	Message.Appendf(TEXT("Shots Fired: %i\n"), ShotsFired);
	Message.Appendf(TEXT("Targets Destroyed: %i\n"), TargetsDestroyed);
	Message.Appendf(TEXT("Accuracy: %4.2f%%\n"), Accuracy);
	Message.Appendf(TEXT("Total Score: %.2f"), GetTotalScore());

	GEngine->AddOnScreenDebugMessage(0, 0.1f, FColor::Yellow, Message);
	GetWorld()->GetTimerManager().SetTimerForNextTick(this, &ATestingTaskGameModeBase::DrawScore);
}

float ATestingTaskGameModeBase::GetTotalScore() const
{
	const float Accuracy = ((TargetsDestroyed + 1.f) / (ShotsFired + 1.f));
	return Score * Accuracy;
}

void ATestingTaskGameModeBase::OnGameFinished()
{
	// TODO: Show a Score Menu.
}

void ATestingTaskGameModeBase::OnTargetDestroyed(ATestingTaskTarget* Target)
{
	Score += Target->GetScore();
	TargetsDestroyed++;

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), TargetDestroyedParticles, Target->GetActorLocation());
}

void ATestingTaskGameModeBase::StartPlay()
{
	Super::StartPlay();

	TargetDestroyedParticles = TargetDestroyedParticlesPointer.LoadSynchronous();
	DrawScore();
}
