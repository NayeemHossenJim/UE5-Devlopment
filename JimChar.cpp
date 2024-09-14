#include "Character/JimChar.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Item/Item.h"
#include "Item/Weapon/Weapon.h"

AJimChar::AJimChar()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 300.f;

	CameraVeiw = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraView"));
	CameraVeiw->SetupAttachment(SpringArm);

	
}

void AJimChar::BeginPlay()
{
	Super::BeginPlay();
	
}

void AJimChar::Forward(float value)
{
	if (Controller && (value != 0.f))
	{
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawInput(0.f, ControlRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawInput).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
}

void AJimChar::Turn(float value)
{
	AddControllerYawInput(value);
}

void AJimChar::LookUp(float value)
{
	AddControllerPitchInput(value);
}

void AJimChar::MoveRight(float value)
{
	const FRotator ControlRotation = GetControlRotation();
	const FRotator YawInput(0.f, ControlRotation.Yaw, 0.f);
	FVector Direction = FRotationMatrix(YawInput).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, value);
}

void AJimChar::EKeyPressed()
{
	AWeapon* OverlappingWeapon = Cast<AWeapon>(OverLappingItem);
	if (OverlappingWeapon)
	{
		OverlappingWeapon->Equip(GetMesh(), FName("RightHandSocket"));
	}
}

void AJimChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AJimChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("Forward"), this, &AJimChar::Forward);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &AJimChar::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &AJimChar::LookUp);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &AJimChar::MoveRight);
	PlayerInputComponent->BindAction(FName("Jump"), IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(FName("Equip"), IE_Pressed, this, &AJimChar::EKeyPressed);
}

