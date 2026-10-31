// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"
class USphereComponent;

enum class EItemState : uint8
{
	EIS_Hovering UMETA(DisplayName = "Hovering"),
	EIS_Equipped UMETA(DisplayName = "Equipped"),
};
UCLASS()
class FIRSTSLASH_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sin Variables")
	float Amplitute = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sin Variables")
	float constantTime = 5.f;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	float RunningTime;
	UFUNCTION(BlueprintPure)
	float TransformedSin();
	EItemState ItemState = EItemState::EIS_Hovering;
	template<typename T>
	T Avg(T first, T second);

	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UPROPERTY(EditAnywhere)
	class UNiagaraComponent* EmbersEffect;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;
};

template<typename T>
inline T AItem::Avg(T first, T second)
{
	return (first+second)/2;
}
