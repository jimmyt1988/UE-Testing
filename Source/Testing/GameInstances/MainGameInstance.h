// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Common.h"
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"

/**
 * MainGameInstance
 */
UCLASS()
class TESTING_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	// 
	UMainGameInstance();

private:

	// Registers IOC dependencies
	void SetUpIOCRegistrations();

};
