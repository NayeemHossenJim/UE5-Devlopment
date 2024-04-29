

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class UDEMY_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
	
	virtual void Tick(float DeltaTime) override;
protected:
	
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Function")
	float Amplitude = 0.25f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Sine Function")
	float TimeConstant = 2.f;
	UFUNCTION(BlueprintPure)
	float TransFormSin(float Value);
	UFUNCTION(BlueprintPure)
	float TransFormCos(float Value);
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;
	template<typename T>
	T Avg(T First, T Second);
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;
};

template<typename T>
inline T AItem::Avg(T First,T Second)
{
	return (First + Second);
}
