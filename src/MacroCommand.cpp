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
    if(spaceAt > 0)
    {
        auto pos = commands.begin() + spaceAt;
        commands.insert(pos, c);
        spaceAt++;
        updateNumber(c, 1);
    }
    else
    {
        // if 0 commands exist, just push it onto the vector
        commands.push_back(c);
        spaceAt++;
        updateNumber(c, 1);
    }    
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
    updateNumber(c, -1);
    spaceAt--;
    }

}

void MacroCommand::execute()
{
    if(spaceAt > 0)
    {
        for(auto it : commands)
        {
            if(it == *(commands.begin() + spaceAt))
            {
                break;
            }

            if(it != NULL)
                it->execute();
        }
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
        Command* com = *(commands.begin() + (spaceAt - 1));

        com->undo();

        spaceAt--; // go back 1 space
        updateNumber(com, -1);
    }
    
}

void MacroCommand::redo()
{
    if(spaceAt < commands.size())
    {
        spaceAt++;

        Command* com = commands.at(spaceAt - 1);

        com->redo();

        updateNumber(com, 1);
    }  
}

void MacroCommand::updateNumber(Command* c, int change)
{
    std::string name = typeid(*c).name();
    std::cout << name << std::endl;

    if(name == "11LegoCommand")
    {
        lego += change;
    }
    else if (name == "13TimberCommand")
    {
        timber += change;
    }
    else if (name == "11ClayCommand")
    {
        clay += change;
    }
    else if (name == "15ConcreteCommand")
    {
        concrete += change;
    }

    std::cout << "Lego: [" << lego << "], Timber: [" << timber << "], Clay: [" << clay << "], Concrete: [" << concrete << "]" << std::endl;
}