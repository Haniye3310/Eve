// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/EveHud.h"
#include "HUD/EveOverlay.h"
#include "Blueprint//UserWidget.h"
void AEveHud::BeginPlay()
{
	Super::BeginPlay();
	UWorld* World = GetWorld();
	if (World) 
	{
		APlayerController* Controller = World->GetFirstPlayerController();
		if (Controller && EveOverlayClass)
		{
			EveOverlay = CreateWidget<UEveOverlay>(Controller, EveOverlayClass);
			EveOverlay->AddToViewport();
		}
	}
}
