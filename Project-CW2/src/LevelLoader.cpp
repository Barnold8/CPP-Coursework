#include "header.h"
#include <string>
#include <sstream>
#include <vector>
#include "LevelLoader.h"

std::vector<int> LevelLoader::intify(std::vector<std::string> data) { // Takes array of strings and gets the numbers out and puts them into an int array (vector)

	std::vector<int> int_data;
	std::string token;
	std::string number;

	for (int i = 0; i < data.size(); i++) {
	
		for (int y = 0; y < data[i].length(); y++) {
			if (data[i][y] == ',') {
	
				int num = std::stoi(number);
				int_data.push_back(num);
				number = "";
			}
			else {
				number += data[i][y];
			}
			
		}
	}
	return int_data;
}

std::string LevelLoader::strSplitByDelim(std::string str, char delim) { // returns string after first find of delim 

	std::string f;
	bool process = false;

	for (int i = 0; i < str.length(); i++) {
		if (process) {
			f += str[i];
		}
		if (str[i] == delim) {
			process = true;
		}
	}
	return f;
}

std::vector<std::vector<std::string>> LevelLoader::TMJData(std::vector<std::string> fileData) {
	
	std::vector<std::vector<std::string>> dataSets;
	std::vector<std::string> data;

	bool process = false;
	
	for (int i = 0; i < fileData.size(); i++) {

		if (fileData[i].find("data") != std::string::npos) {
			process = true;
		}
		else if (fileData[i].find("height") != std::string::npos) {
			process = false;
			dataSets.push_back(data);
			data.clear();
		}
		// Used to only process sections between in data range

		if (process) { // if we are processing the area of the file...
			
			if (fileData[i].find("data") != std::string::npos) {
				std::string a = strSplitByDelim(fileData[i], '[');
				data.push_back(a);
			}
			else {
				data.push_back(fileData[i]);
			}
		}
	}

	for (int i = 0; i < dataSets.size(); i++) {
		for (int y = 0; y < dataSets[i].size(); y++) {
			dataSets[i][y].erase(remove(dataSets[i][y].begin(), dataSets[i][y].end(), ']'), dataSets[i][y].end());
		}
	}

	return dataSets;
}

LevelLoader::LevelLoader(BaseEngine* engine, std::vector<std::string>& spritePaths, std::string TMJ_Path, int tile_w, int tile_h, int w_width, int w_height) : FileIO() {

	m_pEngine = engine;
	m_TMJPath = TMJ_Path;
	m_spritePaths = spritePaths;

	std::vector<std::vector<std::string>> numbers = TMJData(loadFileToLines(TMJ_Path)); // set of integers from TMJ file. 

	for (int i = 0; i < numbers.size(); i++) { // get layers of TMJ numbers and make them into TMJ objects (struct holding integers in a vect)
		std::shared_ptr<TMJ> j = std::make_shared<TMJ>();
		j->IDS = intify(numbers[i]);
		m_TMJS.push_back(j);
	}

	m_tileMaps.push_back(std::make_shared<TileMap>(32, 32, 800 / 32, 800 / 32, m_spritePaths[0], m_TMJS[1], 544, 736,1));
	m_tileMaps.push_back(std::make_shared<TileMap>(32, 32, 800 / 32, 800 / 32, m_spritePaths[1], m_TMJS[2], 512, 2848,392));
	m_tileMaps.push_back(std::make_shared<TileMap>(32, 32, 800 / 32, 800 / 32, m_spritePaths[1], m_TMJS[3], 512, 2848, 392));

}

void LevelLoader::drawTiles() {
	
	for (int i = 0; i < m_tileMaps.size();i++) {
	
		m_tileMaps[i]->drawAllTiles(m_pEngine, m_pEngine->getBackgroundSurface());

	}
	
}

std::vector<std::shared_ptr<TMJ>> LevelLoader::getTMJS() {
	return m_TMJS;
}

std::vector<std::shared_ptr<TileMap>> LevelLoader::getMaps() {
	return m_tileMaps;
}