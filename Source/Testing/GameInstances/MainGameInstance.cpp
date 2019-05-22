// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameInstance.h"
#include "../Services/Abstracts/IPlayerService.h"
#include "../Services/Concretes/PlayerService.h"

UMainGameInstance::UMainGameInstance()
{
	Container.RegisterClass<IPlayerService, PlayerService>();
}