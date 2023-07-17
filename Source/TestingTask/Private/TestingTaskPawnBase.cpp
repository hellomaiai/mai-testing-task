// Do not modify this class
#include "TestingTaskPawnBase.h"

#include "Components/SplineComponent.h"
#include "TestingTaskGameModeBase.h"

// Sets default values
ATestingTaskPawnBase::ATestingTaskPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

// Called when the game starts or when spawned
void ATestingTaskPawnBase::BeginPlay()
{
	Super::BeginPlay();

	AActor* PathActor = PathActorPointer.LoadSynchronous();
	check(PathActor);
	PathSpline = PathActor->FindComponentByClass<USplineComponent>();
	check(PathSpline);
	PathSpline->SetDrawDebug(true);
}

bool ATestingTaskPawnBase::Fire(const FVector2D& Direction)
{
	if (ShotTimer > 0.f)
	{
		return false;
	}

	GetWorld()->SpawnActor<AActor>(ProjectileActorClass, GetActorLocation(), 
		FRotator(FQuat::FindBetween(FVector::ForwardVector, FVector(Direction.X, Direction.Y, 0.f))));

	GetWorld()->GetAuthGameMode<ATestingTaskGameModeBase>()->ShotsFired++;

	ShotTimer = 0.6f;

	return true;
}

bool ATestingTaskPawnBase::IsReadyToFire() const
{
	return ShotTimer <= 0.f;
}

// Called every frame
void ATestingTaskPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FTransform NewTransform = PathSpline->GetTransformAtTime(Progression, ESplineCoordinateSpace::World);
	SetActorTransform(NewTransform);

	if (Progression >= PathSpline->Duration)
	{
		SetActorTickEnabled(false);
		GetWorld()->GetAuthGameMode<ATestingTaskGameModeBase>()->OnGameFinished();
		return;
	}

	if (ShotTimer <= 0.f)
	{
		NotifyIsReadyToFire();
	}

	ShotTimer -= DeltaTime;
	Progression += DeltaTime;
}

