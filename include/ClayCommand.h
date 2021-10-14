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
};

#endif