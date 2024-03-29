#ifndef MACRO_COMMAND_H
#define MACRO_COMMAND_H

#include <vector>
#include <iostream>
#include "Command.h"

class MacroCommand : public Command {
public:
    MacroCommand();
    virtual ~MacroCommand();
    virtual void add(Command* c);
    virtual void remove(Command* c);
    virtual void execute();
    virtual void undo();
    virtual void redo();

private:
    void updateNumber(Command* c, int change);

    std::vector<Command*> commands;

    int spaceAt = 0;

    int lego = 0;
    int timber = 0;
    int concrete = 0;
    int clay = 0;
};

#endif