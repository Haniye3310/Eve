// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SlashAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTSLASH_API USlashAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	class ASlashCharacter* SlashCharacter;
	UPROPERTY(BlueprintReadOnly)
	class UCharacterMovementComponent* SlashCharacterMovement;
	UPROPERTY(BlueprintReadOnly)
	float GroundSpeed;
	UPROPERTY(BlueprintReadOnly)
	bool IsFalling;
};
