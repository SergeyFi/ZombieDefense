// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "ZombieDefense/Components/Character/IndicatorBase.h"
#include "MineralsIndicator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZOMBIEDEFENSE_API UMineralsIndicator : public UIndicatorBase
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMineralsIndicator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float IndicationDelay;

	class UMineralsComponent* MineralsComponent;

	UFUNCTION()
	void OnAddMinerals(float MineralsValue);

	FTimerHandle IndicationTimer;

	void StartIndicationTimer();
		
};
