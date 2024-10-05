#ifndef MACROROUTINE_H
#define MACROROUTINE_H

#include <vector>
#include "Command.h"

class MacroRoutine {
private:
    std::vector<Command*> commands;
public:
    void addProcedure(Command* command);
    void removeProcedure(Command* command);
    void execute();
    ~MacroRoutine();
};

#endif
