#include "Holodeck.h"
#include "SensorRotationCommand.h"
#include "HolodeckSensor.h"

void USensorRotationCommand::Execute() {

	UE_LOG(LogHolodeck, Log, TEXT("SensorRotationCommand::Execute set camera capture rate"));
	//Program should throw an error if any of these params aren't the correct size. They should always be this size.
	if (StringParams.size() != 2 || NumberParams.size() != 3) {
		UE_LOG(LogHolodeck, Error, TEXT("Unexpected argument length found in SensorRotationCommand. Sensor rotation unchanged."));
		return;
	}

	AHolodeckGameMode* GameTarget = static_cast<AHolodeckGameMode*>(Target);
	if (GameTarget == nullptr) {
		UE_LOG(LogHolodeck, Warning, TEXT("UCommand::Target is not a UHolodeckGameMode*. SensorRotationCommand::Execute Sensor rotation unchanged."));
		return;
	}

	UWorld* World = Target->GetWorld();
	if (World == nullptr) {
		UE_LOG(LogHolodeck, Warning, TEXT("SensorRotationCommand::Execute found world as nullptr. Sensor rotation unchanged."));
		return;
	}

	FString AgentName = StringParams[0].c_str();
	FString SensorName = StringParams[1].c_str();
	float X = NumberParams[0];
	float Y = NumberParams[1];
	float Z = NumberParams[2];

	FRotator Rotation;
	Rotation.Roll = X;
	Rotation.Pitch = Y;
	Rotation.Yaw = Z;

	AHolodeckAgent* Agent = GetAgent(AgentName);
	UHolodeckSensor* Sensor = Agent->SensorMap[SensorName];
	Sensor->SetRelativeRotationExact(Rotation);
}
