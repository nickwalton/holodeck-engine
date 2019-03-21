// Fill out your copyright notice in the Description page of Project Settings.

#include "Holodeck.h"
#include "HolodeckGameMode.h"
#include "EditSensorCommand.h"
#include "HolodeckSensor.h"

void UEditSensorCommand::Execute() {
	UE_LOG(LogHolodeck, Log, TEXT("UEditSensorCommand::Add sensor"));

	if (StringParams.size() != 4 || NumberParams.size() != 0) {
		UE_LOG(LogHolodeck, Error, TEXT("Unexpected argument length found in v. Command not executed."));
		return;
	}

	AHolodeckGameMode* GameTarget = static_cast<AHolodeckGameMode*>(Target);
	if (GameTarget == nullptr) {
		UE_LOG(LogHolodeck, Warning, TEXT("UCommand::Target is not a UHolodeckGameMode*. UEditSensorCommand::Sensor not added."));
		return;
	}

	UWorld* World = Target->GetWorld();
	if (World == nullptr) {
		UE_LOG(LogHolodeck, Warning, TEXT("UEditSensorCommand::Execute found world as nullptr. Sensor not added."));
		return;
	}

	FString AgentName = StringParams[0].c_str();
	FString SensorName = StringParams[1].c_str();
	FString MemberName = StringParams[2].c_str();
	FString MemberValue = StringParams[3].c_str();
	AHolodeckAgent* Agent = GetAgent(AgentName);

	UHolodeckSensor* Sensor = Agent->SensorMap[SensorName];
	Sensor->EditSensorMember(MemberName, MemberValue);
}
