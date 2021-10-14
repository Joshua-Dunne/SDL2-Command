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
    spaceAt++;
}

void MacroCommand::remove(Command* c)
{
    if(spaceAt > 0)
    {
        for(std::vector<Command*>::iterator it = commands.begin(); it < commands.end(); it++)
        {
            if (*it == c)
            {
                commands.erase(it);
                break;
            }
        }

    spaceAt--;
    }

}

void MacroCommand::execute()
{
    if(spaceAt > 0)
    {
        for(auto it : commands)
        {
            if(it != NULL)
                it->execute();
        }

    commands.clear();

    }
    else
    {
        std::cout << "No Commands to Execute!" << std::endl;
    }
    
}

void MacroCommand::undo()
{
    if(spaceAt > 0)
    {
        Command* com = *commands.end();

        com->undo();

        spaceAt--; // go back 1 space
    }
    
}

void MacroCommand::redo()
{
    if(spaceAt < commands.size())
    {
        spaceAt++;

        Command* com = commands.at(spaceAt);

        com->redo();
    }  
}