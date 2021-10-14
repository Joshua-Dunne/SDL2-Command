#ifndef TIMBER_COMMAND_H
#define TIMBER_COMMAND_H

#include "Command.h"
#include "Bricks.h"

class TimberCommand : public Command
{
public:
   virtual ~TimberCommand(){
      delete(timber);
   }

   virtual void execute() { 
      timber->draw();
   }

   virtual void undo()
   {
      std::cout << "Removing Timber" << std::endl;
   }

   virtual void redo()
   {
      std::cout << "Re-adding Timber" << std::endl;
   }

private:
   Brick* timber = new TimberBrick();
};

#endif