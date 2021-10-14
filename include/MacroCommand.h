#ifndef MACRO_COMMAND_H
#define MACRO_COMMAND_H

#include <vector>
#include "Command.h"

class MacroCommand : public Command {
public:
    MacroCommand();
    virtual ~MacroCommand();
    virtual void add(Command* c);
    virtual void remove(Command* c);
    virtual void execute();

private:
    std::vector<Command*> commands;
};

#endif