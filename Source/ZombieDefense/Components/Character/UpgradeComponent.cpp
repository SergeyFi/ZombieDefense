// Copyright 2020 Sergey Firsov


#include "UpgradeComponent.h"
#include "ZombieDefense/Components/MineralsComponent.h"

// Sets default values for this component's properties
UUpgradeComponent::UUpgradeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UUpgradeComponent::Upgrade()
{
	auto MineralsComp = GetOwner()->FindComponentByClass<UMineralsComponent>();

	if (MineralsComp)
	{
		if (MineralsComp->GetMinerals() >= MineralsToUpgrade)
		{
			UpgradeVirtual();

			MineralsComp->RemoveMinerals(MineralsToUpgrade);

			MineralsToUpgrade += MineralsUpgradeStep;
		}
	}
}

void UUpgradeComponent::UpgradeVirtual()
{
	
}
