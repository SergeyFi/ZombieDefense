// Copyright 2020 Sergey Firsov


#include "UpgradeComponent.h"
#include "ZombieDefense/Components/MineralsComponent.h"

// Sets default values for this component's properties
UUpgradeComponent::UUpgradeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}

bool UUpgradeComponent::Upgrade()
{
	if (UpgradeStepTotal <= UpgradeLimit || UpgradeLimit == 0)
	{
		auto MineralsComp = GetOwner()->FindComponentByClass<UMineralsComponent>();

		if (MineralsComp)
		{
			if (MineralsComp->GetMinerals() >= MineralsToUpgrade)
			{
				UpgradeVirtual(UpgradeStep);

				MineralsComp->RemoveMinerals(MineralsToUpgrade);

				MineralsToUpgrade += MineralsUpgradeStep;

				UpgradeStepTotal += UpgradeStep;

				LevelCurrent++;

				return true;
			}
		}
	}

	return false;
}

void UUpgradeComponent::UpgradeUnlimit()
{
	UpgradeVirtual(UpgradeStep);

	LevelCurrent++;
}

void UUpgradeComponent::UpgradeAddLevel(int Level)
{
	UpgradeVirtual(UpgradeStep * Level);

	LevelCurrent += Level;
}

int UUpgradeComponent::GetMineralsToUpgrade()
{
	return MineralsToUpgrade;
}

void UUpgradeComponent::UpgradeVirtual(float UpgradeStepNew)
{
	
}
