#ifndef BRICK_H
#define BRICK_H
#include <iostream>

class Brick
{
public:
    virtual ~Brick(){}
    virtual void draw() = 0;
};

class LegoBrick : public Brick
{
    void draw() {std::cout << "Constructing Lego Brick" << std::endl;};
};

class ClayBrick : public Brick
{
    void draw() {std::cout << "Modelling Clay Brick" << std::endl;};
};

class TimberBrick : public Brick
{
    void draw() {std::cout << "Chopping Timber Brick" << std::endl;};
};

class ConcreteBrick : public Brick
{
    void draw() {std::cout << "Mixing Cement for Concrete Brick" << std::endl;};
};

#endif