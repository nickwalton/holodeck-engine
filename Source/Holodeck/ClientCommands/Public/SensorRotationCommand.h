#pragma once

#include "Holodeck.h"

#include "Command.h"
#include "SensorRotationCommand.generated.h"

/**
* SensorRotationCommand
*
*/
UCLASS(ClassGroup = (Custom))
class HOLODECK_API USensorRotationCommand : public UCommand {
	GENERATED_BODY()
public:
	//See UCommand for the documentation of this overridden function. 
	void Execute() override;
};
