#ifndef CLAY_COMMAND_H
#define CLAY_COMMAND_H

#include "Command.h"
#include "Bricks.h"

class ClayCommand : public Command
{
public:
   virtual ~ClayCommand(){
      delete(clay);
   }

   virtual void execute() { 
            clay->draw();
   }

   virtual void undo()
   {
      std::cout << "Removing Clay" << std::endl;
   }

   virtual void redo()
   {
      std::cout << "Re-adding Clay" << std::endl;
   }

private:
   Brick* clay = new ClayBrick();;
};

#endif