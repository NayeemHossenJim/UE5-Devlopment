
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.generated.h"

UCLASS()
class REVISION_API AItems : public AActor
{
	GENERATED_BODY()
	
public:	
	AItems();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameter")
	float Amplitude = 0.75f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameter")
	float TimeConstant = 5.f;

	UFUNCTION(BlueprintPure)
	float TransFormSin();

	UFUNCTION(BlueprintPure)
	float TransFormCos();
private:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, meta =(AllowPrivateAccess="true"))
	float RunningTime;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;
};
