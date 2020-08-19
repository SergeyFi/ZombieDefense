// Copyright 2020 Sergey Firsov


#include "HealthIndicator.h"
#include "ZombieDefense/Components/HealthComponent.h"

UHealthIndicator::UHealthIndicator()
{
    
}

void UHealthIndicator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    UpdateIndicator();
}

void UHealthIndicator::BeginPlay()
{
    Super::BeginPlay();

    HealthComp = GetOwner()->FindComponentByClass<UHealthComponent>();
}

void UHealthIndicator::UpdateIndicator()
{
    if (HealthComp)
    {
        auto HealthCurrent = HealthComp->GetHealth();
        auto HealthMax = HealthComp->GetMaxHealth();

        if (HealthCurrent != HealthMax)
        {
            ShowIndicator();
            TextRender->SetText(FText::FromString(FString::FromInt(int32(HealthCurrent))));
        }
        else
        {
            HideIndicator();
        }
    }
}
