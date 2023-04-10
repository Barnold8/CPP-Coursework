#include "header.h"
#include "TileMap.h"


TileMap::TileMap(int iTileHeight, int iTileWidth, int iMapWidth, int iMapHeight, std::string spritePath) : TileManager(iTileHeight, iTileWidth, iMapWidth, iMapHeight) {
    m_multi_layer = false;
    m_spriteSheet = ImageManager::loadImage(spritePath, true);
}

TileMap::TileMap(int iTileHeight, int iTileWidth, int iMapWidth, int iMapHeight, std::vector<std::string>& spritePaths) : TileManager(iTileHeight, iTileWidth, iMapWidth, iMapHeight) {

    m_multi_layer = true;

    for (int i = 0; i < spritePaths.size();i++) { // goes through all sprite sheet paths and loads image
    
        m_spriteSheets[i] = ImageManager::loadImage(spritePaths[i], true);
    }

}


void TileMap::virtDrawTileAt(BaseEngine* pEngine, DrawingSurface* pSurface, int iMapX, int iMapY, int iStartPositionScreenX, int iStartPositionScreenY) const {
    // WORKING FROM HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
    m_spriteSheet.renderImageWithMask( 
        //pEngine->getBackgroundSurface(), // Surface to draw to 
        //iMapX, iMapY,                    // x and y coord of the tile map
        //32 * iStartPositionScreenX,      
        //32 * iStartPositionScreenY,
        //32,32,0x000000
        pEngine->getBackgroundSurface(),
        0,0,800,800,800,8000,0x000000

    );

    std::cout << "Draw tile at " << std::endl;

}