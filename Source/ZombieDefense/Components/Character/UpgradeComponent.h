// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UpgradeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZOMBIEDEFENSE_API UUpgradeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUpgradeComponent();

	void Upgrade();

protected:

	UPROPERTY(EditAnywhere)
	int MineralsUpgradeStep;

	UPROPERTY(EditAnywhere)
    int MineralsToUpgrade;

	UPROPERTY(EditAnywhere)
	int UpgradeStep;

	virtual void UpgradeVirtual();
		
};
