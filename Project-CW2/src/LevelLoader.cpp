#include "header.h"
#include "LevelLoader.h"


LevelLoader::LevelLoader(BaseEngine* engine, std::string spritePath, int tile_w, int tile_h, int w_width, int w_height) : FileIO() {

	m_tileMap = std::make_shared<TileMap>(tile_w, tile_w, w_width/ tile_w , w_height / tile_h , spritePath);
	m_pEngine = engine;
	m_onlyPath = spritePath;
	
}

LevelLoader::LevelLoader(BaseEngine* engine, std::vector<std::string>& spritePaths, int tile_w, int tile_h, int w_width, int w_height) : FileIO() {

	m_tileMap = std::make_shared<TileMap>(tile_w, tile_w, w_width / tile_w, w_height / tile_h, spritePaths);
	m_spritePaths = spritePaths;
	m_pEngine = engine;

}

void LevelLoader::drawTiles() {
	
	m_tileMap->drawAllTiles(m_pEngine, m_pEngine->getBackgroundSurface());

}