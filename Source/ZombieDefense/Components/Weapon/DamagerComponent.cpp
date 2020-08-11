// Copyright 2020 Sergey Firsov


#include "DamagerComponent.h"
#include "Components/SphereComponent.h"
#include "ZombieDefense/Components/HealthComponent.h"

// Sets default values for this component's properties
UDamagerComponent::UDamagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;

	CriticalDamageMultiplier = 1.0f;
}

void UDamagerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (DetectorShape)
	{
		DetectorShape->OnComponentBeginOverlap.AddDynamic(this, &UDamagerComponent::OnDetectorOverlap);
		DetectorShape->AttachToComponent(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}
}

void UDamagerComponent::OnDetectorOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
                                          class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		auto HealthComp = OtherActor->FindComponentByClass<UHealthComponent>();

		if (HealthComp)
		{
			if (FMath::RandRange(0.0f, 100.0f) <= CriticalDamageChance)
			{
				HealthComp->RemoveHealth(Damage * CriticalDamageMultiplier, GetOwner()->GetInstigator());

				OnCriticalDamage.Broadcast(Damage * CriticalDamageMultiplier);
			}
			else
			{
				HealthComp->RemoveHealth(Damage, GetOwner()->GetInstigator());
			}
			
			DestroyProjectile();
		}
	}
}

void UDamagerComponent::DestroyProjectile()
{
	GetOwner()->Destroy();
}
