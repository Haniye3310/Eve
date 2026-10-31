// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Weapon.generated.h"
class USoundBase;
class UBoxComponent;
/**
 * 
 */
UCLASS()
class FIRSTSLASH_API AWeapon : public AItem
{
	GENERATED_BODY()
public:
	AWeapon();
	void Equip(USceneComponent* InParent, FName InSocketName,AActor* NewOwner, APawn* NewInstigator);
	void DeactivateEmbers();
	void DisableSphereCollision();
	void PlayEquipSound();
	FORCEINLINE UBoxComponent* GetWeaponBox() const { return WeaponBox; }
	void AttachMeshToSocket(USceneComponent* InParent, const FName& InSocketName);
	TArray<AActor*> IgnoreActors;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	bool ActorIsSameType(AActor* OtherActor);
	void ExecuteGetHit(FHitResult& BoxHit);
	UFUNCTION(BlueprintImplementableEvent)
	void CreateFields(const FVector& FieldLocation);  
private:
	UPROPERTY(EditAnywhere, Category = "Weapon Properies")
	USoundBase* EquipSound;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properies")
	UBoxComponent* WeaponBox;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceStart;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceEnd;

	UPROPERTY(EditAnywhere, Category = "Weapon Properies")
	float Damage = 20.f;

	UPROPERTY(EditAnywhere, Category = "Weapon Properies")
	FVector BoxTraceExtent = FVector(5.f);

	UPROPERTY(EditAnywhere, Category = "Weapon Properies")
	bool bShowBoxDebug = false;


	void BoxTrace(FHitResult& BoxHit);

};
