// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Common.h"
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "EnemyPawn.generated.h"

/**
 * The enemy pawn
 */
UCLASS()
class TESTING_API AEnemyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyPawn();

	// Run for when the enemy has been hit
	UFUNCTION()
		void TakeHit();

	// The component that we test collision against
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		UCapsuleComponent* CollisionComponent;

	// The power level of the pawn
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		int Power;

	// The life of the pawn
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		int Life;

};
