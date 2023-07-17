// Fill out your copyright notice in the Description page of Project Settings.
#include "TestingTaskPawn.h"

#include "TestingTaskTarget.h"
#include "EngineUtils.h"

void ATestingTaskPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<AActor*> Targets;
	for(TActorIterator<ATestingTaskTarget> It(GetWorld()); It; ++It)
	{
		Targets.Add(*It);
	}

	if (Targets.Num() == 0)
	{
		return;
	}

	const FVector PlaneLocation = GetActorLocation();

	AActor* ClosestTarget = Targets[0];
	float ClosestDistance = 9999999.f;
	for(AActor* Target : Targets)
	{
		if (Target == nullptr)
		{
			continue;
		}

		const float DistanceToTarget = FVector::Distance(PlaneLocation, Target->GetActorLocation());
		if (DistanceToTarget < ClosestDistance)
		{
			ClosestTarget = Target;
			ClosestDistance = DistanceToTarget;
		}
	}

	const FVector ClosetTargetLocation = ClosestTarget->GetActorLocation();
	Fire(FVector2D(ClosetTargetLocation.X - PlaneLocation.X, ClosetTargetLocation.Y - PlaneLocation.Y));
}

void ATestingTaskPawn::BeginPlay()
{
	Super::BeginPlay();
}
