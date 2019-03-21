#pragma once

#include "Holodeck.h"

#include "HolodeckSensor.h"

#include "Command.h"
#include "EditSensorCommand.generated.h"

/**
* EditSensorCommand
* Command used to edit sensors after initialization.
* Should be called immediately following AddSensorCommand when dynamically adding sensors.
*
* StringParameters expect four arguments, the agent name, sensor name, member name, and new member value.
*/
UCLASS()
class HOLODECK_API UEditSensorCommand : public UCommand
{
	GENERATED_BODY()

public:
	//See UCommand for the documentation of this overridden function.
	void Execute() override;

};
