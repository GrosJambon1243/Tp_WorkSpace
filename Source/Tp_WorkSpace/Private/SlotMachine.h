// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SlotMachine.generated.h"

UCLASS()
class ASlotMachine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASlotMachine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* LeverRoot;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* ReelsRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BoxComp;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* FirstRollComp;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SecondRollComp;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ThirdRollComp;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LeverComp;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LeverCompBase;

};
