#include "MacroRoutine.h"
#include <algorithm>

/**
 * @brief Adds a command to the macro routine.
 * @param command A pointer to the Command object to be added.
 */
void MacroRoutine::addProcedure(Command* command) {
    commands.push_back(command);
}

/**
 * @brief Removes a command from the macro routine.
 * @param command A pointer to the Command object to be removed.
 *
 * This method finds the command in the list and removes it, if found.
 */
void MacroRoutine::removeProcedure(Command* command) {
    auto it = std::find(commands.begin(), commands.end(), command);

    if (it != commands.end()) {
        commands.erase(it);
    }
}

/**
 * @brief Executes all commands in the macro routine.
 *
 * This method iterates through all stored commands and executes each one in the order they were added.
 */
void MacroRoutine::execute() {
    for (Command* command : commands) {
        command->execute();
    }
}

/**
 * @brief Destructor for MacroRoutine.
 *
 * Cleans up all dynamically allocated Command objects stored in the routine, preventing memory leaks.
 */
MacroRoutine::~MacroRoutine() {
    for (Command* command : commands) {
        delete command;
    }
}
