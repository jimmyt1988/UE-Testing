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

	PlayerService = UIOC::Container.GetInstance<IPlayerService>();
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (CollisionComponent)
	{
		CollisionComponent->OnComponentHit.AddUniqueDynamic(this, &APlayerPawn::TriggerVolumeHitOccured);
	}
}

void APlayerPawn::TriggerVolumeHitOccured(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->IsA(AEnemyPawn::StaticClass()))
	{
		AEnemyPawn* EnemyPawn = Cast<AEnemyPawn>(OtherActor);

		// 
		int powerModifier = PlayerService->GetPowerModifier(this);

		// Should be in service, but for brevity:
		if (powerModifier >= EnemyPawn->Power)
		{
			EnemyPawn->TakeHit();
		}
	}
}