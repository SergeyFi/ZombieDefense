// Copyright 2020 Sergey Firsov


#include "CharacterBase.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveUp", this, &ACharacterBase::MoveUp);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACharacterBase::MoveRight);
}

void ACharacterBase::MoveUp(float Value)
{
	AddMovementInput(FVector::ForwardVector * Value);
}

void ACharacterBase::MoveRight(float Value)
{
	AddMovementInput(FVector::RightVector * Value);
}

