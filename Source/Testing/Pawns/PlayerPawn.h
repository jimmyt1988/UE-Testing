// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Common.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Core/Public/Templates/SharedPointer.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "../Services/Abstracts/IPlayerService.h"
#include "PlayerPawn.generated.h"

/**
 * The Player Pawn
 */
UCLASS()
class TESTING_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	// 
	void PostInitializeComponents();

	// Delegate for when collision component interacts with another component
	UFUNCTION(Category = "Custom")
		void TriggerVolumeHitOccured(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	// The component that we test collision against
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		UCapsuleComponent* CollisionComponent;

	// The power level of the pawn
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		int Power;

	// The life of the pawn
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		int Life;

	// The score of the pawn
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		int Score;

private:

	// Instance of player service
	TSharedPtr<struct IPlayerService> PlayerService;

};
