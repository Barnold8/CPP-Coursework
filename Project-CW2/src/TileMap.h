#pragma once
#include "TileManager.h"

struct TMJ;

class TileMap : public TileManager{

	SimpleImage m_spriteSheet;
	int m_image_w;
	int m_image_h;
	int m_offset;

public:

	TileMap(int iTileHeight, int iTileWidth, int iMapWidth, int iMapHeight, std::string spritePath, std::shared_ptr<TMJ> tileData, int iW, int iH, int offset);

	virtual void virtDrawTileAt(BaseEngine* pEngine,DrawingSurface* pSurface,int iMapX, int iMapY,int iStartPositionScreenX, int iStartPositionScreenY) const override;

};

