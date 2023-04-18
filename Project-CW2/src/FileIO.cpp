#include "header.h"
#include "FileIO.h"


std::vector<std::string> FileIO::loadFileToLines(std::string filePath) {

    std::vector<std::string> buffer;
    std::string currLine;
    std::ifstream file(filePath);

    if (file.is_open()) {
        while (std::getline(file, currLine)) {
            //std::cout << currLine << std::endl;
            buffer.push_back(currLine);
        }
        return buffer;

    }
    else {
        std::cout << "Error, unable to open file" << std::endl;
        return buffer;
    }

}