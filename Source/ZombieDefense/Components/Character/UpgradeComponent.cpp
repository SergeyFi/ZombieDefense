// Copyright 2020 Sergey Firsov


#include "UpgradeComponent.h"
#include "ZombieDefense/Components/MineralsComponent.h"

// Sets default values for this component's properties
UUpgradeComponent::UUpgradeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UUpgradeComponent::Upgrade()
{
	if (UpgradeStepTotal <= UpgradeLimit || UpgradeLimit == 0)
	{
		auto MineralsComp = GetOwner()->FindComponentByClass<UMineralsComponent>();

		if (MineralsComp)
		{
			if (MineralsComp->GetMinerals() >= MineralsToUpgrade)
			{
				UpgradeVirtual();

				MineralsComp->RemoveMinerals(MineralsToUpgrade);

				MineralsToUpgrade += MineralsUpgradeStep;

				UpgradeStepTotal += UpgradeStep;
			}
		}
	}
}

void UUpgradeComponent::UpgradeVirtual()
{
	
}
