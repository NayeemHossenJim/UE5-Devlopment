
#include "Items/Items.h"
#include "Revision/DebugMacros.h"

AItems::AItems()
{
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;

}
void AItems::BeginPlay()
{
	Super::BeginPlay();

	

	UE_LOG(LogTemp, Warning, TEXT("Hello,How are you gays"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Black, FString("Welcome to HELL"));
	}
}

float AItems::TransFormSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}
float AItems::TransFormCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

void AItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;

	/*
	if (GEngine)
	{
		FString Msg = GetName();
		FString Name = FString::Printf(TEXT("Name Of the Character : %s"), *Msg);
		UE_LOG(LogTemp, Warning, TEXT("DeltaTime : %s"), *Msg);
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Black,Name);
	}

	UWorld* World = GetWorld();
	SetActorLocation(FVector(0.f, 0.f, 100.f));
	FVector SLocation = GetActorLocation();
	FVector Forward = GetActorForwardVector() * 100.f;
	FVector ELocation = SLocation + Forward;
	float MovementRate = 50.f * DeltaTime;
	float DeltaZ = Amplitude * FMath::Sin(RunningTime*TimeConstant);
	float RotationRate = 45.f * DeltaTime;
	AddActorWorldOffset(FVector(MovementRate, 0.f, DeltaZ));
	SetActorRotation(FRotator(0.f, 45.f, 0.f));
	AddActorWorldRotation(FRotator(0.f, RotationRate, 0.f));
	DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_SingleFrame(SLocation, ELocation);
	*/

	
	
	
}

