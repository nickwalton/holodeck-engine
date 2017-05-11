// Fill out your copyright notice in the Description page of Project Settings.

#include "Holodeck.h"
#include "HolodeckSensor.h"


// Sets default values for this component's properties
UHolodeckSensor::UHolodeckSensor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	bOn = true;
}


// Called when the game starts
void UHolodeckSensor::BeginPlay()
{
	Super::BeginPlay();

	// Get the controller of the agent this is attached to
	Controller = (AHolodeckPawnController*)(this->GetAttachmentRootActor()->GetInstigator()->Controller);
	if (Controller != nullptr)
	{
		AHolodeckAgent* Agent = (AHolodeckAgent*)(Controller->GetPawn());
		if (Agent != nullptr)
			ResultData.AgentName = Agent->AgentName;
		ResultData.Key = GetDataKey();

		Controller->Subscribe(ResultData, GetDataLength());
	}
}


// Called every frame
void UHolodeckSensor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (bOn && Controller != nullptr) {
		TickSensorComponent(DeltaTime, TickType, ThisTickFunction);
		Controller->Publish(ResultData);
	}
}
