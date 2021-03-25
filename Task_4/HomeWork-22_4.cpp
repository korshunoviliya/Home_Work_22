#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream picture;
    std::string pathFile;
    std::cout << "Enter the absolute path to the text file: ";
    std::cin >> pathFile;
    std::string fileExtension = pathFile.substr( pathFile.length() - 4);
    if (fileExtension != ".png") {
        std::cerr << "File is NOT format PNG\n";
        return 0;
    }
    char buffer[4];
    picture.open(pathFile, std::ios::binary);

    if (picture.is_open()) {
         picture.read(buffer, 4);
         if (buffer[0] = -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G') {
             std::cerr << "File is format PNG\n";
         }
         else std::cerr << "File is NOT format PNG\n";
    }
    else std::cerr << "File is not open!!!" << std::endl;

    picture.close();
}