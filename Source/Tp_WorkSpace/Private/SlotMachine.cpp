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
	
	BoxComp2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxComp2"));
	BoxComp2 -> SetupAttachment(SceneRoot);

	FirstRollComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FirstRoll"));
	FirstRollComp ->SetupAttachment(ReelsRoot);

	SecondRollComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondRoll"));
	SecondRollComp ->SetupAttachment(ReelsRoot);

	ThirdRollComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ThirdRoll"));
	ThirdRollComp->SetupAttachment(ReelsRoot);

	LeverComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lever"));
	LeverComp->SetupAttachment(LeverRoot);

	initialPos.SetRotation(FQuat(FRotator(0.f,0.f,0.f)));

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
	float leverAngle = LeverComp->GetRelativeTransform().GetRotation().X;
	//if (LeverComp->GetRelativeTransform().GetRotation().X > 0)
	//{
		leverAngle -=  DeltaTime * 30;
		
		LeverComp->SetRelativeRotation(FRotator(0.f,0.f,FMath::Max(leverAngle,0)),true);
	//}
	

}

void ASlotMachine::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if (LeverComp->GetRelativeTransform().GetRotation().Equals(initialPos.GetRotation()))
	{
		LeverComp->SetRelativeRotation(FRotator(0.f,0.f,45.f),true);
		RotateReels(FirstRollComp);
		RotateReels(SecondRollComp);
		RotateReels(ThirdRollComp);
	}

	
}

int ASlotMachine::RotateReels(UStaticMeshComponent* theReels)
{
	int RandomInt = FMath::RandRange(0,15);
	float reelAngle = 22.5 * RandomInt;
	theReels->SetRelativeRotation(FRotator(reelAngle,90.f,90.f),true);
	return RandomInt;
}

