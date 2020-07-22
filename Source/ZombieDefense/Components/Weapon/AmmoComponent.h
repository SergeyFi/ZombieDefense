// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AmmoComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZOMBIEDEFENSE_API UAmmoComponent : public UActorComponent
{
	GENERATED_BODY()


public:

	UAmmoComponent();
	
	void AddAmmo(int AmmoIncrease);

	void RemoveAmmo(int AmmoRemoved);

	float GetReloadTime();

	void SetReloadTime(float ReloadTimeNew);

protected:
	
	void BindToFireComponent();

	UFUNCTION()
	void OnProjectileSpawned(AActor* Projectile);

	void BlockFire();

	void UnblockFire();

	UPROPERTY(EditAnywhere)
	int Ammo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int ClipSizeInitial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int ClipSizeCurrent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ReloadTime;

	UPROPERTY(EditAnywhere)
	bool bInfinityAmmo;

	void RemoveAmmoClip(int AmmoRemoved);

	virtual void BeginPlay() override;

	void Reload();

	FTimerHandle ReloadTimer;
	
};
