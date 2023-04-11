#pragma once
#include "TileManager.h"

struct TMJ;

class TileMap : public TileManager{

	//, std::vector<std::string>& spritePaths,
	
	bool m_multi_layer;

	SimpleImage m_spriteSheet; // for when one layer is only drawn

	std::vector<SimpleImage> m_spriteSheets; // for when multiple layers are drawn

public:

	TileMap(int iTileHeight, int iTileWidth, int iMapWidth, int iMapHeight, std::vector<std::string>& spritePaths, std::vector<std::shared_ptr<TMJ>> tileData);

	virtual void virtDrawTileAt(BaseEngine* pEngine,DrawingSurface* pSurface,int iMapX, int iMapY,int iStartPositionScreenX, int iStartPositionScreenY) const override;

};

