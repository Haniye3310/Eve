// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"
#include <Characters/SlashCharacter.h>
#include "NiagaraComponent.h"
// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	ItemMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	ItemMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(RootComponent);
	EmbersEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Embers"));
	EmbersEffect->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	/*UE_LOG(LogTemp,Warning,TEXT("Hello"));
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(1,60.f,FColor::Blue,FString("Item Begin"));
	}
	UWorld* world = GetWorld();
	if (world) {
		SetActorLocation(FVector(0,0,100.f));
		SetActorRotation(FRotator(0,0,45.f));
		AddActorWorldOffset(FVector(0,0,200));
		AddActorWorldRotation(FRotator(0,0,45.f));
		FVector vector = GetActorLocation();
		FVector scaledForwardVector = GetActorForwardVector()*100;
		FVector endPoint = vector + scaledForwardVector;
		DrawDebugSphere(world,vector,20.f,24,FColor::Red,false,30.f);
		DrawDebugLine(world,vector,endPoint,FColor::Red,true,30.f);
		DrawDebugPoint(world,vector,15,FColor::Red,false,30.f);
	}

	int32 avg = Avg<int32>(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("Avg of a and 3: %d"), avg);*/
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this,&AItem::OnSphereEndOverlap);
}

float AItem::TransformedSin()
{
	return Amplitute * FMath::Sin(RunningTime * constantTime);
}

void AItem::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ASlashCharacter* SlashCharacter = Cast<ASlashCharacter>(OtherActor);
	if (SlashCharacter)
	{
		SlashCharacter->SetOverlappingItem(this);
	}
}

void AItem::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ASlashCharacter* SlashCharacter = Cast<ASlashCharacter>(OtherActor);
	if (SlashCharacter)
	{
		SlashCharacter->SetOverlappingItem(nullptr);
	}
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning,TEXT("DeltaTime: %f"), DeltaTime);
	//FString Message = FString::Printf(TEXT("DeltaTime: %f"), DeltaTime);
	//if (GEngine) {
	//	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Blue, Message);
	//}

	//AddActorWorldOffset(FVector(20 * DeltaTime, 0.f, 0.f));

	RunningTime += DeltaTime;
	if (ItemState == EItemState::EIS_Hovering) 
	{
		AddActorWorldOffset(FVector(0.f, 0.f, TransformedSin()));

	}
	/*UWorld* world = GetWorld();
	if (world) {
		DrawDebugSphere(world,GetActorLocation(),20.f,20, FColor::Red,false,-1.f,0,10);
	}*/
}

