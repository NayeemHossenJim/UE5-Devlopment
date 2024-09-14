#include "Item/Item.h"
#include "DebugMacros.h"
#include "Components/SphereComponent.h"
#include "Character/JimChar.h"
AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	SetRootComponent(ItemMesh);

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnSphereOverLap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AItem::OnSphereEndLap);
}

float AItem::TransFormSin(float Value)
{
	
	return Amplitude * FMath::Sin(Value * TimeConstant);
}

float AItem::TransFormCos(float Value)
{
	return Amplitude * FMath::Cos(Value * TimeConstant);
}

void AItem::OnSphereOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AJimChar* JimChar = Cast<AJimChar>(OtherActor);
	if (JimChar)
	{
		JimChar->SetOverLappingItem(this);
	}
}

void AItem::OnSphereEndLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AJimChar* JimChar = Cast<AJimChar>(OtherActor);
	if (JimChar)
	{
		JimChar->SetOverLappingItem(nullptr);
	}
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;
	float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);
	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();
	FVector EndLocation = Location + Forward * 50.f;
	//AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));
	//AddActorWorldRotation(FRotator(0.f,5.f,0.f));
}

