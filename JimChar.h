#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "JimChar.generated.h"

class USpringArmComponent;
class UCameraComponent;
class AItem;
UCLASS()
class SRS_API AJimChar : public ACharacter
{
	GENERATED_BODY()

public:
	
	AJimChar();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	
	virtual void BeginPlay() override;
private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraVeiw;

	void Forward(float value);
	void Turn(float value);
	void LookUp(float value);
	void MoveRight(float value);
	void EKeyPressed();
private:
	UPROPERTY(VisibleInstanceOnly)
	AItem* OverLappingItem;
public:
	FORCEINLINE void SetOverLappingItem(AItem* Item) { OverLappingItem = Item; }
};
