#include "TurnOffCommand.h"

/**
 * @brief Constructs a TurnOffCommand object for the given smart device.
 * @param dev A pointer to the SmartDevice that the command will control.
 */
TurnOffCommand::TurnOffCommand(SmartDevice* dev) : device(dev) {}

/**
 * @brief Executes the command by turning off the smart device.
 *
 * This method calls the performAction() method on the associated smart device.
 */
void TurnOffCommand::execute() {
    device->performAction();
}
