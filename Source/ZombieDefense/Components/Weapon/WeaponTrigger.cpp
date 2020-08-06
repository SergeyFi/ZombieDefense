// Copyright 2020 Sergey Firsov


#include "WeaponTrigger.h"

#include "FireComponent.h"

// Sets default values for this component's properties
UWeaponTrigger::UWeaponTrigger()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UWeaponTrigger::Fire()
{
	TArray<UFireComponent*> Fires;
	
	GetOwner()->GetComponents(Fires);

	for (auto Fire : Fires)
	{
		if (Fire)
		{
			Fire->FireStart();
		}
	}
}

void UWeaponTrigger::FireStop()
{
	TArray<UFireComponent*> Fires;
	
	GetOwner()->GetComponents(Fires);

	for (auto Fire : Fires)
	{
		if (Fire)
		{
			Fire->FireStop();
		}
	}
}
