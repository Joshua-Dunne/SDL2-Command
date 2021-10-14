#ifndef CONCRETE_COMMAND_H
#define CONCRETE_COMMAND_H

#include "Command.h"
#include "Bricks.h"

class ConcreteCommand : public Command
{
public:
  virtual void execute() { 
      Brick* concrete = new ConcreteBrick();

      concrete->draw();

      delete(concrete);
   }

   virtual void undo()
   {
      std::cout << "Removing Concrete" << std::endl;
   }

   virtual void redo()
   {
      std::cout << "Re-adding Concrete" << std::endl;
   }
};

#endif