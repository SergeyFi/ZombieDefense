// Copyright 2020 Sergey Firsov


#include "MineralsComponent.h"
#include "ZombieDefense/Components/HealthComponent.h"

void UMineralsComponent::BeginPlay()
{
    Super::BeginPlay();

    BindToOwnerHealth();
}

void UMineralsComponent::AddMinerals(int Amount)
{
    Minerals += Amount;
}

void UMineralsComponent::RemoveMinerals(int Amount)
{
    Minerals -= Amount;

    if (Minerals <= 0)
    {
        Minerals = 0;
    }
}

int UMineralsComponent::GetMinerals()
{
    return Minerals;
}

void UMineralsComponent::AddMineralsToKiller(AActor* Instigator, float Health)
{
    if (Instigator)
    {
        auto MineralsComponent = Instigator->FindComponentByClass<UMineralsComponent>();

        if (MineralsComponent)
        {
            MineralsComponent->AddMinerals(Minerals);
            Minerals = 0;
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
