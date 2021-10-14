#include "../include/MacroCommand.h"

MacroCommand::MacroCommand()
{
    // empty
}

MacroCommand::~MacroCommand()
{
    execute();
}

void MacroCommand::add(Command* c)
{
    commands.push_back(c);
}

void MacroCommand::remove(Command* c)
{
}

void MacroCommand::execute()
{
    for(auto it : commands)
    {
        it->execute();
    }

    commands.clear();
}