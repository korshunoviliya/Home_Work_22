#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream text;
    std::string pathFile;
    std::cout << "Enter the absolute path to the text file: ";
    std::cin >> pathFile;
    char buffer[25];

    text.open(pathFile, std::ios::binary);

    if (text.is_open()) {
        while(!text.eof()) {
            text.read(buffer, sizeof(buffer) - 1);
            buffer[text.gcount()] = 0;
            std::cout << buffer;
        }
    }
    else std::cout << "File is not open!!!" << std::endl;

    text.close();
    return 0;
}