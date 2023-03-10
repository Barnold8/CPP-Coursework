#pragma once

#include "../src/TileManager.h"


class TileMap :  public TileManager{

    // Tilemap is an overlay kind of thing that works as a grid for drawing to for easy GUI management

    // Tile width and height is the size of a grid piece and map is the size of the area encompassing the screen

public:

    TileMap() 
        : TileManager(40, 40, 100, 100) 
    { 
    }

    TileMap(int TW, int TH, int MW, int MH) 
        : TileManager(TW, TH, MW, MH) 
    { 
    }

        virtual void virtDrawTileAt( 
        BaseEngine* pEngine, DrawingSurface* pSurface,int iMapX, int iMapY, int iStartPositionScreenX, int iStartPositionScreenY) const override;

    void drawClouds(BaseEngine* p_engine);

};