// Copyright 2020 Sergey Firsov


#include "DamagerComponent.h"
#include "Components/SphereComponent.h"
#include "ZombieDefense/Components/HealthComponent.h"

// Sets default values for this component's properties
UDamagerComponent::UDamagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	CriticalDamageMultiplier = 1.0f;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereOverlap"));
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &UDamagerComponent::OnSphereOverlap);
	Sphere->SetupAttachment(this);
}


// Called when the game starts
void UDamagerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UDamagerComponent::OnSphereOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
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