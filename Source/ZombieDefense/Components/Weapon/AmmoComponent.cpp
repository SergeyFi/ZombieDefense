// Copyright 2020 Sergey Firsov


#include "AmmoComponent.h"
#include "FireComponent.h"

UAmmoComponent::UAmmoComponent()
{
    ClipSizeInitial = 1;
    ClipSizeCurrent = ClipSizeInitial;
    ReloadTime = 1.0f;
    bInfinityAmmo = true;
}

void UAmmoComponent::BeginPlay()
{
    Super::BeginPlay();

    BindToFireComponent();

}

void UAmmoComponent::BindToFireComponent()
{
    TArray<UFireComponent*> FireComponents;
    GetOwner()->GetComponents<UFireComponent>(FireComponents);

    for (auto FireComponent : FireComponents)
    {
        if (FireComponent)
        {
            FireComponent->OnProjectileSpawned.AddDynamic(this, &UAmmoComponent::OnProjectileSpawned);
        }
    }
}

void UAmmoComponent::OnProjectileSpawned(AActor* Projectile)
{
    RemoveAmmoClip(1);
}

void UAmmoComponent::RemoveAmmoClip(int AmmoRemoved)
{
    ClipSizeCurrent -= AmmoRemoved;

    if (ClipSizeCurrent <= 0)
    {
        ClipSizeCurrent = 0;

        BlockFire();
        
        Reload();
    }
}

void UAmmoComponent::BlockFire()
{
    TArray<UFireComponent*> FireComponents;
    GetOwner()->GetComponents<UFireComponent>(FireComponents);

    for (auto FireComponent : FireComponents)
    {
        if (FireComponent)
        {
            FireComponent->BlockFire();
        }
    }
}

void UAmmoComponent::Reload()
{
    ClipSizeCurrent = ClipSizeInitial;

    RemoveAmmo(ClipSizeInitial);
    
    GetWorld()->GetTimerManager().SetTimer(ReloadTimer, this, &UAmmoComponent::UnblockFire,
        ReloadTime, false, ReloadTime);
}

void UAmmoComponent::UnblockFire()
{
    TArray<UFireComponent*> FireComponents;
    GetOwner()->GetComponents<UFireComponent>(FireComponents);

    for (auto FireComponent : FireComponents)
    {
        if (FireComponent)
        {
            FireComponent->UnblockFire();
        }
    }
}

void UAmmoComponent::AddAmmo(int AmmoIncrease)
{
    Ammo += AmmoIncrease;

    if (Ammo > 0)
    {
        UnblockFire();
    }
}

void UAmmoComponent::RemoveAmmo(int AmmoRemoved)
{
    if (!bInfinityAmmo)
    {
        Ammo -= AmmoRemoved;

        if (Ammo <= 0)
        {
            Ammo = 0;
        }
    }
}

float UAmmoComponent::GetReloadTime()
{
    return ReloadTime;
}

void UAmmoComponent::SetReloadTime(float ReloadTimeNew)
{
    ReloadTime = ReloadTimeNew;
}
