#ifndef LEGO_COMMAND_H
#define LEGO_COMMAND_H

#include "Command.h"
#include "Bricks.h"

class LegoCommand : public Command
{
public:
  virtual void execute() { 
      Brick* lego = new LegoBrick();

      lego->draw();

      delete(lego);
   }

   virtual void undo()
   {
      std::cout << "Removing Lego" << std::endl;
   }

   virtual void redo()
   {
      std::cout << "Re-adding Lego" << std::endl;
   }
};

#endif