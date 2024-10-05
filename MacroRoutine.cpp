#include "MacroRoutine.h"
#include <algorithm>

void MacroRoutine::addProcedure(Command* command) {
    commands.push_back(command);
}

void MacroRoutine::removeProcedure(Command* command) {
    auto it = std::find(commands.begin(), commands.end(), command);

    if (it != commands.end()) {
        commands.erase(it);
    }
}

void MacroRoutine::execute() {
    for (Command* command : commands) {
        command->execute();
    }
}

MacroRoutine::~MacroRoutine() {
    for (Command* command : commands) {
        delete command;
    }
}
