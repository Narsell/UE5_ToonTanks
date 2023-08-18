// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* StaticMesh{};

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	class UProjectileMovementComponent* ProjectileMovement{};

	UPROPERTY(VisibleAnywhere, Category="Combat")
	class UParticleSystemComponent* TrailParticles{};
	
	UPROPERTY(EditAnywhere, Category="Combat")
	float Damage{ 50.f };

	UPROPERTY(EditAnywhere, Category="Combat")
	class UParticleSystem* HitParticles{};

	UPROPERTY(EditAnywhere, Category="Combat")
	class USoundBase* LaunchSound{};

	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* HitSound{};

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass{};

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
