#pragma once
#include "FileIO.h"
#include "Image.h"
#include "TileMap.h"
#include "BaseEngine.h"

struct TMJ {

	std::vector<int> IDS;

};

class LevelLoader : public FileIO
{

private:

	BaseEngine* m_pEngine;

	std::string m_onlyPath;
	
	std::string m_TMJPath;

	std::vector<std::string> m_spritePaths;

	std::vector<std::shared_ptr<TMJ>> m_TMJS;

	std::vector<std::shared_ptr<TileMap>> m_tileMaps; // used for rendering tiles

public:

	LevelLoader(BaseEngine* engine, std::vector<std::string>& spritePaths, std::string TMJ_Path, int tile_w, int tile_h, int w_width, int w_height);

	std::vector<int> intify(std::vector<std::string> data);

	std::string strSplitByDelim (std::string str, char delim);

	std::vector<std::vector<std::string>> TMJData(std::vector<std::string> fileData);

	std::vector<std::shared_ptr<TMJ>> getTMJS();

	std::vector<std::shared_ptr<TileMap>> getMaps();

	void drawTiles();

};