#include "../src/header.h"
#include "TileMap.h"


void Psybw7TileManager::virtDrawTileAt(BaseEngine* pEngine, DrawingSurface* pSurface,int iMapX, int iMapY, int iStartPositionScreenX, int iStartPositionScreenY) const{

    pSurface->drawOval (
                        iStartPositionScreenX, // Left
                        iStartPositionScreenY, // Top
                        iStartPositionScreenX + getTileWidth() - 1, // Right
                        iStartPositionScreenY + getTileHeight() - 1, // Bottom
                        this->getMapValue(iMapX, iMapY));

}



void Psybw7TileManager::drawCloud(BaseEngine* p_engine, int x, int y, int mapX){


    int Adj = 25;

    DrawingSurface* dSurf = p_engine->getBackgroundSurface();
    int dSurfWidth = dSurf->getSurfaceWidth();

    // Cloud
    this->virtDrawTileAt(p_engine,p_engine->getBackgroundSurface(),mapX,0,x,y-Adj);
    this->virtDrawTileAt(p_engine,p_engine->getBackgroundSurface(),mapX,1,x-Adj,y);
    this->virtDrawTileAt(p_engine,p_engine->getBackgroundSurface(),mapX,2,x,y);
    this->virtDrawTileAt(p_engine,p_engine->getBackgroundSurface(),mapX,3,x+Adj,y);
    this->virtDrawTileAt(p_engine,p_engine->getBackgroundSurface(),mapX,4,x,y+ Adj);
    // Cloud

    // if(main->m_tile_map.isValidTilePosition(m_iCurrentScreenX, m_iCurrentScreenY)) // Clicked within tiles?
    //     {
    //         int mapX = main->m_tile_map.getMapXForScreenX(m_iCurrentScreenX); // Which column?
    //         int mapY = main->m_tile_map.getMapYForScreenY(m_iCurrentScreenY); // Which row?
    //         int value =main-> m_tile_map.getMapValue(mapX, mapY); // Current value?
    //        main->m_tile_map.setAndRedrawMapValueAt(mapX, mapY, value+rand(), main, main->getBackgroundSurface() );
    //         redrawDisplay(); // Force background to be redrawn to foreground
    //     }

}

