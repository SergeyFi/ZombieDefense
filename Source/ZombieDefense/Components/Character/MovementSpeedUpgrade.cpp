// Copyright 2020 Sergey Firsov


#include "MovementSpeedUpgrade.h"

#include "GameFramework/CharacterMovementComponent.h"

void UMovementSpeedUpgrade::UpgradeVirtual(float UpgradeStepNew)
{
    auto CharacterMovementComp = GetOwner()->FindComponentByClass<UCharacterMovementComponent>();

    if (CharacterMovementComp)
    {
        CharacterMovementComp->MaxWalkSpeed += UpgradeStepNew;
    }
}
