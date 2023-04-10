#pragma once
#include <fstream>
#include <vector>

class FileIO
{

public:

	static std::vector<std::string> loadFileToLines(std::string filePath);

};

