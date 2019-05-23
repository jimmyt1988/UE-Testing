// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "../GameInstances/MainGameInstance.h"
#include "EnemyPawn.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(FName("APlayerPawn_CollisionComponent"));

	// Fetch PlayerService from IOC container
	PlayerService = UIOC::Container.GetInstance<IPlayerService>();
}

void APlayerPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	// Set up collision component actions
	if (CollisionComponent)
	{
		CollisionComponent->OnComponentHit.AddUniqueDynamic(this, &APlayerPawn::TriggerVolumeHitOccured);
	}
}

void APlayerPawn::TriggerVolumeHitOccured(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	// If hit component is an enemy pawn
	if (OtherActor->IsA(AEnemyPawn::StaticClass()))
	{
		// Cast the actor we interacted with, to an enemy pawn
		AEnemyPawn* EnemyPawn = Cast<AEnemyPawn>(OtherActor);

		// Get the power modifier for player
		int powerModifier = PlayerService->GetPowerModifier(this);

		// For example purposes, does a simple bit of logic to demonstrate test
		// Note: Should be in service, but for brevity:
		if (powerModifier >= EnemyPawn->Power)
		{
			// Issue damage to enemy
			EnemyPawn->TakeHit();
		}
	}
}