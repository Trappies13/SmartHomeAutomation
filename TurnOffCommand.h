#ifndef TURNOFFCOMMAND_H
#define TURNOFFCOMMAND_H

#include "Command.h"
#include "SmartDevice.h"

class TurnOffCommand : public Command {
private:
    SmartDevice* device;
public:
    TurnOffCommand(SmartDevice* dev);
    void execute() override;
};

#endif
