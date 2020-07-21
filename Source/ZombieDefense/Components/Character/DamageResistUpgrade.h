// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "UpgradeComponent.h"
#include "DamageResistUpgrade.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZOMBIEDEFENSE_API UDamageResistUpgrade : public UUpgradeComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDamageResistUpgrade();

protected:

	virtual void UpgradeVirtual() override;
		
};
