#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "JimAnim.generated.h"

class AJimChar;
class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class SRS_API UJimAnim : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime);
	UPROPERTY(BlueprintReadOnly)
	AJimChar* JimChar;
	UPROPERTY(BlueprintReadOnly)
	UCharacterMovementComponent* JimMove;
	UPROPERTY(BlueprintReadOnly)
	float GroundSpeed;
	UPROPERTY(BlueprintReadOnly)
	bool IsFalling;
};
