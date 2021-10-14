#ifndef CLAY_COMMAND_H
#define CLAY_COMMAND_H

#include "Command.h"
#include "Bricks.h"

class ClayCommand : public Command
{
public:
  virtual void execute() { 
      Brick* clay = new ClayBrick();

      clay->draw();

      delete(clay);
   }

   virtual void undo()
   {
      std::cout << "Removing Clay" << std::endl;
   }

   virtual void redo()
   {
      std::cout << "Re-adding Clay" << std::endl;
   }
};

#endif