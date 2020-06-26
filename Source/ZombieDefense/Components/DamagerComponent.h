// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DamagerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZOMBIEDEFENSE_API UDamagerComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDamagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	class USphereComponent* Sphere;

	void OnSphereOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void DestroyProjectile();

public:
	UPROPERTY(EditAnywhere)
	float Damage;
};
