// Copyright 2020 Sergey Firsov


#include "HealthUpgrade.h"


#include "ZombieDefense/Components/HealthComponent.h"

// Sets default values for this component's properties
UHealthUpgrade::UHealthUpgrade()
{
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UHealthUpgrade::BeginPlay()
{
	Super::BeginPlay();
	
}

void UHealthUpgrade::UpgradeVirtual()
{
	auto HealthComponent = GetOwner()->FindComponentByClass<UHealthComponent>();

	if (HealthComponent)
	{
		HealthComponent->IncreaseMaxHealth(UpgradeStep);
	}
}
