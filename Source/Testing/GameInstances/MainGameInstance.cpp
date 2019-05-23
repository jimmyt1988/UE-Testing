// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameInstance.h"
#include "Runtime/Core/Public/Misc/TypeContainer.h"
#include "../Services/Abstracts/IPlayerService.h"
#include "../Services/Concretes/PlayerService.h"

UMainGameInstance::UMainGameInstance()
{
	SetUpIOCRegistrations();
}

void UMainGameInstance::SetUpIOCRegistrations()
{
	UIOC::Container.RegisterClass<IPlayerService, PlayerService>();
}