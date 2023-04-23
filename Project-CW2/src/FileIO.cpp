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

void FileIO::writeToFile(bool update, std::string path,std::string data) {

   
    if (update) {
        std::ofstream myfile;
        myfile.open(path, std::ios::out | std::ios::app);
        myfile << data;
        myfile.close();
    }
    else {
        std::ofstream ofs(path, std::ofstream::trunc);
        ofs << data;

        ofs.close();
    
    }

}

bool FileIO::isFile(std::string path) {
    std::ifstream file;
    file.open(path);
    return file.good();
}
