#include "header.h"
#include "TileMap.h"
#include "LevelLoader.h"



TileMap::TileMap(int iTileHeight, int iTileWidth, int iMapWidth, int iMapHeight, std::vector<std::string>& spritePaths, std::vector<std::shared_ptr<TMJ>> tileData) : TileManager(iTileHeight, iTileWidth, iMapWidth, iMapHeight) {

    m_multi_layer = true;

    for (int i = 0; i < spritePaths.size();i++) { // goes through all sprite sheet paths and loads image
    
        m_spriteSheets.push_back(ImageManager::loadImage(spritePaths[i], true));
    }

}


void TileMap::virtDrawTileAt(BaseEngine* pEngine, DrawingSurface* pSurface, int iMapX, int iMapY, int iStartPositionScreenX, int iStartPositionScreenY) const {

    // Render IMAGE

        //Source = where it starts to be drawn from (start of rect to be drawn from image, aka selection of it)
        //width  = source + width AKA the width from the source
        //height = same premise as width
        //target = where to draw on screen

    // Render IMAGE

    m_spriteSheet.renderImage( 
        pEngine->getBackgroundSurface(), // Surface to draw to 
        100, 20,                    // x and y coord of the tile map
        10,10,
        32,32
    );
}


