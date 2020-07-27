// Copyright 2020 Sergey Firsov


#include "WeaponHolder.h"

// Sets default values for this component's properties
UWeaponHolder::UWeaponHolder()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}

AActor* UWeaponHolder::GetWeapon()
{
	return Weapon;
}

void UWeaponHolder::BeginPlay()
{
	Super::BeginPlay();

	SpawnWeapon();
}

void UWeaponHolder::SpawnWeapon()
{
	auto World = GetWorld();

	if (World && WeaponClass)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		
		Weapon = World->SpawnActor<AActor>(WeaponClass, GetComponentTransform(), SpawnParameters);

		Weapon->AttachToComponent(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}
}

