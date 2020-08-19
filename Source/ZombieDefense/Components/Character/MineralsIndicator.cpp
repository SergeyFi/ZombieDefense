// Copyright 2020 Sergey Firsov

#include "MineralsIndicator.h"
#include "ZombieDefense/Components/MineralsComponent.h"
#include "Components/TextRenderComponent.h"


// Sets default values for this component's properties
UMineralsIndicator::UMineralsIndicator()
{
	PrimaryComponentTick.bCanEverTick = true;

	IndicationDelay = 1.0f;
}


// Called when the game starts
void UMineralsIndicator::BeginPlay()
{
	Super::BeginPlay();

	TextRender->SetVisibility(false);

	MineralsComponent = GetOwner()->FindComponentByClass<UMineralsComponent>();

	if (MineralsComponent)
	{
		MineralsComponent->OnAddMinerals.AddDynamic(this, &UMineralsIndicator::OnAddMinerals);
	}
}

void UMineralsIndicator::OnAddMinerals(float MineralsValue)
{
	TextRender->SetText(FText::FromString( "+" + FString::FromInt(int32(MineralsValue))));

	ShowIndicator();

	StartIndicationTimer();
}

void UMineralsIndicator::StartIndicationTimer()
{
	GetWorld()->GetTimerManager().SetTimer(IndicationTimer, this, &UMineralsIndicator::HideIndicator,
		 IndicationDelay, false, IndicationDelay);
}