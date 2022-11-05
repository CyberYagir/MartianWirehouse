


#include "FPSController.h"

// Sets default values
AFPSController::AFPSController()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPSController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &AFPSController::MoveVertical);
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &AFPSController::MoveHorizontal);
	PlayerInputComponent->BindAxis(TEXT("MouseX"), this, &AFPSController::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("MouseY"), this, &AFPSController::AddControllerPitchInput);
}

void AFPSController::MoveVertical(float axis)
{
	AddMovementInput(GetActorForwardVector() * axis);
}

void AFPSController::MoveHorizontal(float axis)
{
	AddMovementInput(GetActorRightVector() * axis);
}


