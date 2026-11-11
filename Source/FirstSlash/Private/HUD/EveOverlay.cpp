// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/EveOverlay.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

void UEveOverlay::SetHealthBarPercent(float Percent)
{
	if (HealthProgressBar) 
	{
		HealthProgressBar->SetPercent(Percent);
	}
}

void UEveOverlay::SetStaminaBarPercent(float Percent)
{
	if (StaminaProgressBar) 
	{
		StaminaProgressBar->SetPercent(Percent);
	}
}

void UEveOverlay::SetGold(int32 Gold)
{
	if (GoldText) 
	{
		GoldText->SetText(FText::FromString(FString::Printf(TEXT("%d"),Gold)));
	}
}

void UEveOverlay::SetSouls(int32 Souls)
{
	if (SoulsText) 
	{
		SoulsText->SetText(FText::FromString(FString::Printf(TEXT("%d"), Souls)));
	}
}
