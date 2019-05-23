// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPawn.h"

// Sets default values
AEnemyPawn::AEnemyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Instantiate the collision component
	CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(FName("AEnemyPawn_CollisionComponent"));
}

void AEnemyPawn::TakeHit()
{
	// Should really be in a service, but for brevity:
	Life -= 1;
}