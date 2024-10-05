#ifndef TURNOFFCOMMAND_H
#define TURNOFFCOMMAND_H

#include "Command.h"
#include "SmartDevice.h"

/**
 * @class TurnOffCommand
 * @brief A concrete command class that turns off a smart device in the home automation system.
 *
 * The TurnOffCommand class implements the Command interface. It encapsulates the action
 * of turning off a specific smart device.
 */
class TurnOffCommand : public Command {
private:
    SmartDevice* device; ///< A pointer to the smart device that will be turned off.
public:
    /**
     * @brief Constructs a new TurnOffCommand object for a specific smart device.
     * @param dev A pointer to the SmartDevice that the command will operate on.
     */
    TurnOffCommand(SmartDevice* dev);

    /**
     * @brief Executes the command to turn off the smart device.
     *
     * This method calls the performAction() method on the associated smart device.
     */
    void execute() override;
};

#endif
