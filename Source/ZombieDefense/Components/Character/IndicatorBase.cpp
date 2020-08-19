// Copyright 2020 Sergey Firsov


#include "IndicatorBase.h"
#include "Components/TextRenderComponent.h"
#include "ZombieDefense/Components/MineralsComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values for this component's properties
UIndicatorBase::UIndicatorBase()
{
	PrimaryComponentTick.bCanEverTick = true;

	TextRender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextRender"));
	TextRender->SetupAttachment(this);
}


// Called when the game starts
void UIndicatorBase::BeginPlay()
{
	Super::BeginPlay();

	TextRender->DetachFromComponent(FDetachmentTransformRules::KeepRelativeTransform);

	OwnerCamera = GetOwner()->FindComponentByClass<UCameraComponent>();

	TargetRotation = GetComponentRotation();
	TargetLocation = GetRelativeLocation();
	
}

void UIndicatorBase::RotateIndicatorToCamera(float DeltaTime)
{
	TextRender->SetWorldRotation(TargetRotation);
	TextRender->SetWorldLocation(TargetLocation + GetOwner()->GetActorLocation());
}

// Called every frame
void UIndicatorBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	RotateIndicatorToCamera(DeltaTime);
}

