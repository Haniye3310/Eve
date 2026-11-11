// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "EveHud.generated.h"

/**
 * 
 */
class UEveOverlay;
UCLASS()
class FIRSTSLASH_API AEveHud : public AHUD
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditDefaultsOnly, Category = "Eve")
	TSubclassOf<UEveOverlay> EveOverlayClass;
	UPROPERTY()
	UEveOverlay* EveOverlay;
public:
	FORCEINLINE UEveOverlay* GetEveOverlay() const { return EveOverlay; }
};
