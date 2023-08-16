// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	void HandleDestruction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void RotateTurret(FVector LookAtLocation);
	void Fire();

private:

	UPROPERTY(EditDefaultsOnly, Category="Components")
	class UCapsuleComponent* CapsuleComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float TurretRotationRate{15.f};

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	TSubclassOf<class AProjectile> ProjectileClass{};

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
