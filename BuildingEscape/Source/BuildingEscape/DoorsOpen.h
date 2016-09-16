// Copyright Viet Pham 2016.

#pragma once

#include "Components/ActorComponent.h"
#include "DoorsOpen.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UDoorsOpen : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorsOpen();
    
    void OpenDoor();
    
    void CloseDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
    UPROPERTY(EditAnywhere)
    float OpenAngle = -90.0f;
    
    UPROPERTY(EditAnywhere)
    ATriggerVolume* PressurePlate;
    
    UPROPERTY(EditAnywhere)
    float DoorCloseDelay = 0.5f;
    
    float LastDoorOpenTime;
    
    // Return total mass in kg
    float GetTotalMassOfActorsOnPlate();
    
    AActor* Owner; //The owning door
};
