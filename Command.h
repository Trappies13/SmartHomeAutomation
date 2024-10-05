#ifndef COMMAND_H
#define COMMAND_H

#include "SmartDevice.h"

/**
 * @class Command
 * @brief An abstract class representing a command to be executed on a smart device.
 *
 * The Command class defines an interface for executing operations on smart devices. 
 * It follows the Command Design Pattern, encapsulating actions as objects that can be executed.
 */
class Command {
public:
    /**
     * @brief Executes the command.
     *
     * This is a pure virtual method that will be implemented by derived classes to
     * perform specific actions on a smart device.
     */
    virtual void execute() = 0;
    
    /**
     * @brief Virtual destructor.
     *
     * Ensures that derived class destructors are called properly.
     */
    virtual ~Command() = default;
};

#endif
