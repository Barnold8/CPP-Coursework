#pragma once

#include "BaseEngine.h"
#include "Office_Apocalypse.h"
#include "LevelLoader.h"


struct rect {

    int x;
    int y;
    int w;
    int h;
   
};


class Collider
{

protected:

    int ID;

public:

	virtual int getColAtPixel(int x, int y) = 0;

    rect rectToRect(rect r1, rect r2);

    virtual rect getRect() = 0;

	int isCollided(BaseEngine* engine);

    int getID();

    bool canMove(std::shared_ptr<LevelLoader> LL, int x, int y, bool isFloor);// engine is temp

};

