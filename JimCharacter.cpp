// Fill out your copyright notice in the Description page of Project Settings.


#include "JimCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AJimCharacter::AJimCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);

	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationPitch = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 300.f;

	ViewPort = CreateDefaultSubobject<UCameraComponent>(TEXT("VeiwPort"));
	ViewPort->SetupAttachment(CameraBoom);

}

// Called when the game starts or when spawned
void AJimCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJimCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AJimCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AJimCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &AJimCharacter::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &AJimCharacter::LookUp);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &AJimCharacter::MoveRight);
	
}

void AJimCharacter::MoveForward(float value)
{
	if (Controller && (value != 0.f))
	{
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
}

void AJimCharacter::MoveRight(float value)
{
	if (Controller && (value != 0.f))
	{
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	}
}

void AJimCharacter::Turn(float value)
{
	AddControllerYawInput(value);
}

void AJimCharacter::LookUp(float value)
{
	AddControllerPitchInput(value);
}

