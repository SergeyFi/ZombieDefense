// Copyright 2020 Sergey Firsov


#include "DamagerComponent.h"
#include "Components/SphereComponent.h"
#include "ZombieDefense/Components/HealthComponent.h"

// Sets default values for this component's properties
UDamagerComponent::UDamagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &UDamagerComponent::OnSphereOverlap);
	Sphere->SetupAttachment(GetAttachmentRoot());
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
			HealthComp->RemoveHealth(Damage);
			DestroyProjectile();
		}
	}
}

void UDamagerComponent::DestroyProjectile()
{
	GetOwner()->Destroy();
}
