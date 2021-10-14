#ifndef CONCRETE_COMMAND_H
#define CONCRETE_COMMAND_H

#include "Command.h"
#include "Bricks.h"

class ConcreteCommand : public Command
{
public:
   virtual ~ConcreteCommand(){
      delete(concrete);
   }

   virtual void execute() { 
      concrete->draw();
   }

   virtual void undo()
   {
      std::cout << "Removing Concrete" << std::endl;
   }

   virtual void redo()
   {
      std::cout << "Re-adding Concrete" << std::endl;
   }

private:
   Brick* concrete = new ConcreteBrick();
};

#endif