#pragma once

#include "../src/TileManager.h"


class Psybw7TileManager :  public TileManager{

    // Tilemap is an overlay kind of thing that works as a grid for drawing to for easy GUI management

    // Tile width and height is the size of a grid piece and map is the size of the area encompassing the screen

public:

    Psybw7TileManager() 
        : TileManager(40, 40, 100, 100) 
    { 
        for(int i = 0; i < 10; i++){
            setMapValue(i,0,0xFFFFFF);
            setMapValue(i,1,0xFFFFFF);
            setMapValue(i,2,0xFFFFFF);
            setMapValue(i,3,0xFFFFFF);
            setMapValue(i,4,0xFFFFFF); 
        }
        

    }

    Psybw7TileManager(int TW, int TH, int MW, int MH) 
        : TileManager(TW, TH, MW, MH) 
    { 
    }

        virtual void virtDrawTileAt( 
        BaseEngine* pEngine, DrawingSurface* pSurface,int iMapX, int iMapY, int iStartPositionScreenX, int iStartPositionScreenY) const override;

    void drawCloud(BaseEngine* p_engine, int x, int y, int mapX);


};