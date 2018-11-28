// Fill out your copyright notice in the Description page of Project Settings.

#include "Player_Character.h"


// Sets default values
APlayer_Character::APlayer_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayer_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayer_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayer_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Input Bindings
	InputComponent->BindAxis("Forward", this, &APlayer_Character::Forward);
	InputComponent->BindAxis("Right", this, &APlayer_Character::Right);
	

	InputComponent->BindAction("Run", IE_Pressed, this, &APlayer_Character::EnableRun);
	InputComponent->BindAction("Run", IE_Released, this, &APlayer_Character::DisableRun);
}


//Handles forward and backwards character motion
void APlayer_Character::Forward(float Value)
{
	if (Controller && Value)
		if (bIsRunning)
		{
			Value *= 2;
		}
	{
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, Value / 2);
	}
}

//handles right and left character motion
void APlayer_Character::Right(float Value)
{
	if (Controller && Value)
		if (bIsRunning)
		{
			Value *= 2;
		}
	{
		FVector Right = GetActorRightVector();
		AddMovementInput(Right, Value / 2);
	}
}

void APlayer_Character::EnableRun()
{
	bIsRunning = true;
}

void APlayer_Character::DisableRun()
{
	bIsRunning = false;
}

