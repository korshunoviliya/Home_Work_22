#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream picture;
    std::string pathFile;
    std::cout << "Enter the absolute path to the text file: ";
    std::cin >> pathFile;
    char buffer[4];

    picture.open(pathFile, std::ios::binary);

    if (picture.is_open()) {
         picture.read(buffer, 4);
         if (buffer[0] = -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G') {
             std::cout << "File is format PNG\n";
         }
         else std::cout << "File is NOT format PNG\n";
    }
    else std::cout << "File is not open!!!" << std::endl;

    picture.close();

}
