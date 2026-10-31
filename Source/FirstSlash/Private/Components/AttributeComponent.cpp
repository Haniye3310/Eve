

#include "Components/AttributeComponent.h"

UAttributeComponent::UAttributeComponent()
{
	
	PrimaryComponentTick.bCanEverTick = true;

}


void UAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	
}
bool UAttributeComponent::IsAlive()
{
	return Health > 0;
}

void UAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UAttributeComponent::RecieveDamage(float Damage)
{
	Health = FMath::Clamp(Health-Damage,0,MaxHealth);
}

float UAttributeComponent::GetHealthPercent()
{
	return Health/MaxHealth;
}

