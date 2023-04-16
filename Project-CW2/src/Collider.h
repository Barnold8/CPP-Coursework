#pragma once

#include "BaseEngine.h"

struct rect {

    int x;
    int y;
    int w;
    int h;

};


class Collider
{

public:

	virtual int getColAtPixel(int x, int y) = 0;

    rect rectToRect(rect r1, rect r2);

    virtual rect getRect() = 0;



};

