// Copyright Viet Pham 2016.

#include "BuildingEscape.h"
#include "DoorsOpen.h"


// Sets default values for this component's properties
UDoorsOpen::UDoorsOpen()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorsOpen::BeginPlay()
{
	Super::BeginPlay();
    
    //Find the owning Actor
    Owner = GetOwner();

    //a Pawn is an Actor
    ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UDoorsOpen::OpenDoor()
{
    //Create a rotator
    //FRotator NewRotation = FRotator(0.0f, -90.0f, 0.0f);
    
    //Set the door rotation
    Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
}

void UDoorsOpen::CloseDoor()
{
    //Create a rotator
    //FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f);
    
    //Set the door rotation
    Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}

// Called every frame
void UDoorsOpen::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Poll the Trigger volume
    //If the ActorThatOpens is in the volume
    if(PressurePlate->IsOverlappingActor(ActorThatOpens))
    {
        OpenDoor();
        LastDoorOpenTime = GetWorld()->GetTimeSeconds();
    }
    
    //Check if it's time to close door
    if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay) {
        CloseDoor();
    }
}

