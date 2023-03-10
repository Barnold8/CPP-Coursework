#include "../src/header.h"
#include "TileMap.h"


void TileMap::virtDrawTileAt(BaseEngine* pEngine, DrawingSurface* pSurface,int iMapX, int iMapY, int iStartPositionScreenX, int iStartPositionScreenY) const{

    pSurface->drawOval (
                        iStartPositionScreenX, // Left
                        iStartPositionScreenY, // Top
                        iStartPositionScreenX + getTileWidth() - 1, // Right
                        iStartPositionScreenY + getTileHeight() - 1, // Bottom
                        0xFFFFFF);

}



void TileMap::drawClouds(BaseEngine* p_engine){

    const int LMAX = 30;
    const int ADJ = 30;
    DrawingSurface* dSurf = p_engine->getBackgroundSurface();
    int dSurfWidth = dSurf->getSurfaceWidth();

    for(int i = LMAX; i < dSurfWidth; i++){
        if(i % 200 == 0){
            // Cloud
            this->virtDrawTileAt(p_engine,p_engine->getBackgroundSurface(),0,0,i-ADJ,80);
            this->virtDrawTileAt(p_engine,p_engine->getBackgroundSurface(),0,0,i,80);
            this->virtDrawTileAt(p_engine,p_engine->getBackgroundSurface(),0,0,i,54);
            this->virtDrawTileAt(p_engine,p_engine->getBackgroundSurface(),0,0,i,104);
            this->virtDrawTileAt(p_engine,p_engine->getBackgroundSurface(),0,0,i+ADJ,80);
            // Cloud
        }
        

    }

}
