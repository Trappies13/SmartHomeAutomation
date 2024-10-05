#ifndef COMMAND_H
#define COMMAND_H

#include "SmartDevice.h"

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

#endif
