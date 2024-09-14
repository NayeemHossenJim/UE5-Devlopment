#include "Character/JimAnim.h"
#include "Character/JimChar.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UJimAnim::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	JimChar = Cast<AJimChar>(TryGetPawnOwner());
	if (JimChar)
	{
		JimMove = JimChar->GetCharacterMovement();
	}
}

void UJimAnim::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	if (JimMove)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(JimMove->Velocity);
		IsFalling = JimMove->IsFalling();
	}
}
