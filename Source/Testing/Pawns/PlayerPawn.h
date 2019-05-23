// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Common.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Core/Public/Templates/SharedPointer.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "../Services/Abstracts/IPlayerService.h"
#include "PlayerPawn.generated.h"

UCLASS()
class TESTING_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	// 
	void PostInitializeComponents();

	// 
	void BeginPlay();

	// 
	UFUNCTION(Category = "Custom")
		void TriggerVolumeHitOccured(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	// 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		UCapsuleComponent* CollisionComponent;

	// 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		int Power;

	// 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		int Life;

	// 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		int Score;

private:

	TSharedPtr<struct IPlayerService> PlayerService;

};
