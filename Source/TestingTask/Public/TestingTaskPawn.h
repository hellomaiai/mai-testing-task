// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestingTaskPawnBase.h"
#include "TestingTaskPawn.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGTASK_API ATestingTaskPawn : public ATestingTaskPawnBase
{
	GENERATED_BODY()
	
protected:
	void Tick(float DeltaTime) override;
	void BeginPlay() override;
};
