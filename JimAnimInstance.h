// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "JimAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class HI_API UJimAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float Deltatime) override;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	class AJimCharacter* JimCharacter;
	UPROPERTY(BlueprintReadOnly)
	class UCharacterMovementComponent* JimCharacterMovement;
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	float GroundSpeed;
};
