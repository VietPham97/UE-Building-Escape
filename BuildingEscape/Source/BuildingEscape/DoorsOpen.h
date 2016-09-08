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

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
    UPROPERTY(VisibleAnywhere)
    float OpenAngle = 90.0f;
    
    UPROPERTY(EditAnywhere)
    ATriggerVolume* PressurePlate;
};
