#pragma once

#include "TileManager.h"
#include "header.h"

class MyTileManager : TileManager{


    MyTileManager() 
        : TileManager(20, 20, 15, 15) 
    { 
    }

};