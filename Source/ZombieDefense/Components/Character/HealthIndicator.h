// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "Zombiedefense/Components/Character/IndicatorBase.h"
#include "HealthIndicator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZOMBIEDEFENSE_API UHealthIndicator : public UIndicatorBase
{
	GENERATED_BODY()

public:

	UHealthIndicator();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

	virtual void BeginPlay() override;

private:

	class UHealthComponent* HealthComp;

	void UpdateIndicator();
	
};
