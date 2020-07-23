// Copyright 2020 Sergey Firsov


#include "AmountComponent.h"

// Sets default values for this component's properties
UAmountComponent::UAmountComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;

}


// Called when the game starts
void UAmountComponent::BeginPlay()
{
	Super::BeginPlay();

}

float UAmountComponent::GetAmount()
{
	return Amount;
}

void UAmountComponent::SetAmount(float AmountNew)
{
	Amount = AmountNew;
}

void UAmountComponent::AddAmount(float AmountIncrease)
{
	Amount += AmountIncrease;
}

void UAmountComponent::RemoveAmount(float AmountDecrease)
{
	Amount -= AmountDecrease;

	if (Amount < 0.0f)
	{
		Amount = 0.0f;
	}
}


