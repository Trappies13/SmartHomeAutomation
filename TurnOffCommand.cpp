#include "TurnOffCommand.h"

TurnOffCommand::TurnOffCommand(SmartDevice* dev) : device(dev) {}

void TurnOffCommand::execute() {
    device->performAction();
}
