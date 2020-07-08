// Copyright 2020 Sergey Firsov


#include "MineralsComponent.h"
#include "ZombieDefense/Components/HealthComponent.h"


void UMineralsComponent::BeginPlay()
{
    Super::BeginPlay();

    BindToOwnerHealth();
}

void UMineralsComponent::AddMineralsToKiller(AActor* Instigator, float Health)
{
    if (Instigator)
    {
        auto MineralsComponent = Instigator->FindComponentByClass<UMineralsComponent>();

        if (MineralsComponent)
        {
            MineralsComponent->AddAmount(Amount);
            Amount = 0.0f;
        }
    }
}

void UMineralsComponent::BindToOwnerHealth()
{
    if (bAddMineralsToKiller)
    {
        auto HealthComponent = GetOwner()->FindComponentByClass<UHealthComponent>();

        if (HealthComponent)
        {
            HealthComponent->OnHealthEnded.AddDynamic(this, &UMineralsComponent::AddMineralsToKiller);
        }
    }
}
