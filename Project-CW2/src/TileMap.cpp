#include "header.h"
#include "TileMap.h"
#include "LevelLoader.h"



TileMap::TileMap(int iTileHeight, int iTileWidth, int iMapWidth, int iMapHeight, std::string spritePath, std::shared_ptr<TMJ> tileData, int iW, int iH, int offset) : TileManager(iTileHeight, iTileWidth, iMapWidth, iMapHeight) {
    

    m_spriteSheet = ImageManager::loadImage(spritePath, true);
    m_image_h = iH;
    m_image_w = iW;
    m_offset  = offset;

    for (int x = 0; x < iMapWidth; x++) {
        for (int y = 0; y < iMapHeight; y++) {
            setMapValue(x, y, tileData->IDS[y * iMapHeight + x]);
        }
    }
}

void TileMap::virtDrawTileAt(BaseEngine* pEngine, DrawingSurface* pSurface, int iMapX, int iMapY, int iStartPositionScreenX, int iStartPositionScreenY) const {

    // Render IMAGE

        //Source = where it starts to be drawn from (start of rect to be drawn from image, aka selection of it)
        //width  = source + width AKA the width from the source
        //height = same premise as width
        //target = where to draw on screen

    // Render IMAGE

    int times = 32;
    int mx = (getMapValue(iMapX, iMapY) - m_offset);
    int x = (mx % (m_image_w / 32)) * times;
    int y = (mx / (m_image_w / 32)) * times;

    

    if (mx > -1) { // if map value is not set
        m_spriteSheet.renderImageWithMask(
            pEngine->getBackgroundSurface(), // Surface to draw to 
            x, y,                            // x and y coord of the tile map
            iStartPositionScreenX, iStartPositionScreenY,
            32, 32,
            0x00FF00
        );
    }

}


