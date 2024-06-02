// Fill out your copyright notice in the Description page of Project Settings.


#include "JimAnimInstance.h"
#include "JimCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UJimAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	JimCharacter = Cast<AJimCharacter>(TryGetPawnOwner());
	if (JimCharacter)
	{
		JimCharacterMovement =JimCharacter->GetCharacterMovement();
	}
}

void UJimAnimInstance::NativeUpdateAnimation(float Deltatime)
{
	Super::NativeUpdateAnimation(Deltatime);
	if (JimCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(JimCharacterMovement->Velocity);
	}
}
