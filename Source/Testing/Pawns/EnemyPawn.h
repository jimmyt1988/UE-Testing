// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Common.h"
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "EnemyPawn.generated.h"

UCLASS()
class TESTING_API AEnemyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyPawn();

	UFUNCTION()
		void TakeHit();

	// 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		UCapsuleComponent* CollisionComponent;

	// 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		int Power;

	// 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		int Life;

};
