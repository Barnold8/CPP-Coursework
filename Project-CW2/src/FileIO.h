#pragma once
#include <fstream>
#include <vector>

class FileIO
{

public:

	static std::vector<std::string> loadFileToLines(std::string filePath);

	static void writeToFile(bool update, std::string path, std::string data);

	static bool isFile(std::string path);

};

