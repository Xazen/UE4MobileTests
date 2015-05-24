// Fill out your copyright notice in the Description page of Project Settings.

#include "PerformanceTest.h"
#include "TouchGameMode.h"

// ButtonMenu
#include "ButtonMenu.h"

ATouchGameMode::ATouchGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	HUDClass = AButtonMenu::StaticClass();

}




