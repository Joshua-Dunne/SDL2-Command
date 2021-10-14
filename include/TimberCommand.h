#ifndef TIMBER_COMMAND_H
#define TIMBER_COMMAND_H

#include "Command.h"
#include "Bricks.h"

class TimberCommand : public Command
{
public:
  virtual void execute() { 
      Brick* timber = new TimberBrick();

      timber->draw();

      delete(timber);
   }
};

#endif