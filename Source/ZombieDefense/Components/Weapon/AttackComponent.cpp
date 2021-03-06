// Copyright 2020 Sergey Firsov


#include "AttackComponent.h"
#include "TimerManager.h"
#include "ZombieDefense/Components/HealthComponent.h"

// Sets default values for this component's properties
UAttackComponent::UAttackComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;

	Damage = 1.0f;
	DamageRate = 1.0f;
}

void UAttackComponent::StartCoolDown()
{
	GetWorld()->GetTimerManager().SetTimer(
        AttackTimer, this, &UAttackComponent::StopCoolDown,
        DamageRate, false, DamageRate
        );
}

void UAttackComponent::StopCoolDown()
{
	CoolDown = false;
}

void UAttackComponent::AttackTarget(AActor* Target)
{
	if (!CoolDown && Target)
	{
		auto HealthComp = Target->FindComponentByClass<UHealthComponent>();

		if (HealthComp)
		{
			HealthComp->RemoveHealth(Damage, GetOwner());
		}

		CoolDown = true;
		
		StartCoolDown();
	}
}
