#include "Item/Item.h"
#include  "DebugMacros.h"


AItem::AItem()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	SetRootComponent(ItemMesh);
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	//Practice Session
	/*SetActorLocation(FVector(0.f, 0.f, 100.f));
	SetActorRotation(FRotator(25.f,45.f,0.f));
	FVector Start = GetActorLocation();
	FVector ForwardVector = GetActorForwardVector();
	FVector End = Start + ForwardVector * 50.f;
	UWorld* World = GetWorld();
	DRAW_SPHERE(Start);
	DRAW_VECTOR(Start, End);*/
}

float AItem::TransFormSin(float Value)
{
	return Amplitude * FMath::Sin(Value * TimeConstant);
}

float AItem::TransFormCos(float Value)
{
	return Amplitude* FMath::Cos(Value * TimeConstant);
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;
	//Practice Session
	//float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);
	//FVector Start = GetActorLocation();
	//FVector ForwardVector = GetActorForwardVector();
	//FVector End = Start + ForwardVector * 50.f;
	//UWorld* World = GetWorld();
	//DRAW_SPHERE_SingleFrame(Start);
	//DRAW_VECTOR_SingleFrame(Start, End);
	//AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));
	//AddActorWorldRotation(FRotator(0.f,Rotation,0.f));
}

