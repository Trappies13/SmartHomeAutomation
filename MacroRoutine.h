#ifndef MACROROUTINE_H
#define MACROROUTINE_H

#include <vector>
#include "Command.h"

/**
 * @class MacroRoutine
 * @brief A class that manages a sequence of commands in a home automation system.
 *
 * The MacroRoutine class allows users to create a sequence of commands (e.g., turn off all lights, lock all doors) 
 * and execute them in order. It can store, add, remove, and execute a list of commands.
 */
class MacroRoutine {
private:
    std::vector<Command*> commands; ///< A vector that stores the sequence of commands.
public:
    /**
     * @brief Adds a command to the macro routine.
     * @param command A pointer to the Command object to be added.
     */
    void addProcedure(Command* command);

    /**
     * @brief Removes a command from the macro routine.
     * @param command A pointer to the Command object to be removed.
     */
    void removeProcedure(Command* command);

    /**
     * @brief Executes all commands in the macro routine in the order they were added.
     */
    void execute();

    /**
     * @brief Destructor for MacroRoutine.
     *
     * Ensures all dynamically allocated Command objects are deleted to prevent memory leaks.
     */
    ~MacroRoutine();
};

#endif
