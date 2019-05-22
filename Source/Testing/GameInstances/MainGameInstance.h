// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Runtime/Core/Public/Misc/TypeContainer.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TESTING_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UMainGameInstance();

	TTypeContainer<> Container;

};
