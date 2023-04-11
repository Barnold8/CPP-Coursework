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

//LevelLoader::LevelLoader(BaseEngine* engine, std::string spritePath, std::string TMJ_Path, int tile_w, int tile_h, int w_width, int w_height) : FileIO() {
//
//	std::vector<std::vector<std::string>> numbers = TMJData(loadFileToLines(TMJ_Path)); // set of integers from TMJ file. 
//
//	for (int i = 0; i < numbers.size(); i++) { // get layers of TMJ numbers and make them into TMJ objects (struct holding integers in a vect)
//		std::shared_ptr<TMJ> j = std::make_shared<TMJ>();
//		j->IDS = intify(numbers[i]);
//		m_TMJS.push_back(j);
//	}
//
//	m_tileMap = std::make_shared<TileMap>(tile_w, tile_w, w_width/ tile_w , w_height / tile_h , spritePath, m_TMJS[0]); // only give m_TMJS[0] since this level loader only has one layer to handle
//	m_pEngine = engine;
//	m_onlyPath = spritePath;
//	m_TMJPath = TMJ_Path;
//
//
//}

LevelLoader::LevelLoader(BaseEngine* engine, std::vector<std::string>& spritePaths, std::string TMJ_Path, int tile_w, int tile_h, int w_width, int w_height) : FileIO() {

	m_pEngine = engine;
	m_TMJPath = TMJ_Path;

	std::vector<std::vector<std::string>> numbers = TMJData(loadFileToLines(TMJ_Path)); // set of integers from TMJ file. 

	for (int i = 0; i < numbers.size(); i++) { // get layers of TMJ numbers and make them into TMJ objects (struct holding integers in a vect)
		std::shared_ptr<TMJ> j = std::make_shared<TMJ>();
		j->IDS = intify(numbers[i]);
		m_TMJS.push_back(j);
	}

	m_spritePaths = spritePaths;

	m_tileMap = std::make_shared<TileMap>(32, 32, 800 / 32, 800 / 32, m_spritePaths, m_TMJS);

}

void LevelLoader::drawTiles() {
	
	//m_tileMap->drawAllTiles(m_pEngine, m_pEngine->getBackgroundSurface());

}