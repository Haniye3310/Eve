

#include "Components/AttributeComponent.h"

UAttributeComponent::UAttributeComponent()
{
	
	PrimaryComponentTick.bCanEverTick = false;

}


void UAttributeComponent::RegenStamina(float DeltaTime)
{
	Stamina = FMath::Clamp(Stamina + StaminaRegenrate * DeltaTime, 0.f, MaxStamina);
}

void UAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	
}
bool UAttributeComponent::IsAlive()
{
	return Health > 0;
}

void UAttributeComponent::AddSouls(int32 NumberOfSouls)
{
	Souls += NumberOfSouls;
}

void UAttributeComponent::AddGold(int32 AmountOfGold)
{
	Gold += AmountOfGold;
}

void UAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UAttributeComponent::RecieveDamage(float Damage)
{
	Health = FMath::Clamp(Health-Damage,0,MaxHealth);
}

void UAttributeComponent::UseStamina(float StaminaCost)
{
	Stamina = FMath::Clamp(Stamina - StaminaCost, 0, MaxStamina);

}

float UAttributeComponent::GetHealthPercent()
{
	return Health/MaxHealth;
}

float UAttributeComponent::GetStaminaPercent()
{
	return Stamina/MaxStamina;
}

