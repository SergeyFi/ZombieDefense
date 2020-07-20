// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AmountComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZOMBIEDEFENSE_API UAmountComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAmountComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float Amount;

public:

	UFUNCTION(BlueprintCallable)
	float GetAmount();

	UFUNCTION(BlueprintCallable)
	void SetAmount(float AmountNew);

	UFUNCTION(BlueprintCallable)
	virtual void AddAmount(float AmountIncrease);

	UFUNCTION(BlueprintCallable)
	void RemoveAmount(float AmountDecrease);

		
};
