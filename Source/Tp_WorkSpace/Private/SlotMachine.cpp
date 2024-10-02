// Fill out your copyright notice in the Description page of Project Settings.


#include "SlotMachine.h"

// Sets default values
ASlotMachine::ASlotMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneComp");
	RootComponent = SceneRoot;

	LeverRoot = CreateDefaultSubobject<USceneComponent>("LeverRoot");
	LeverRoot -> SetupAttachment(SceneRoot);

	ReelsRoot = CreateDefaultSubobject<USceneComponent>("ReelsRoot");
	ReelsRoot -> SetupAttachment(SceneRoot);
	
	BoxComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxComp"));
	BoxComp -> SetupAttachment(SceneRoot);

	FirstRollComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FirstRoll"));
	FirstRollComp ->SetupAttachment(ReelsRoot);

	SecondRollComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondRoll"));
	SecondRollComp ->SetupAttachment(ReelsRoot);

	ThirdRollComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ThirdRoll"));
	ThirdRollComp->SetupAttachment(ReelsRoot);

	LeverComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lever"));
	LeverComp->SetupAttachment(LeverRoot);

}

// Called when the game starts or when spawned
void ASlotMachine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASlotMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

