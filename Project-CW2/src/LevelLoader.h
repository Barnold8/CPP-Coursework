#pragma once
#include "FileIO.h"
#include "Image.h"
#include "TileMap.h"
#include "BaseEngine.h"


class LevelLoader : public FileIO
{

private:

	BaseEngine* m_pEngine;

	std::shared_ptr<TileMap> m_tileMap;

	std::string m_onlyPath;

	std::vector<std::string> m_spritePaths;

public:

	LevelLoader(BaseEngine* engine, std::string spritePath, int tile_w, int tile_h, int w_width, int w_height); // this assumes there is one layer for a level

	LevelLoader(BaseEngine* engine, std::vector<std::string>& spritePaths, int tile_w, int tile_h, int w_width, int w_height); // this assumes multiple layers for a level

	void drawTiles();

};