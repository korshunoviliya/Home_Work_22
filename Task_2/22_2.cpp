#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::ifstream text;
    std::string word;
    std::string pathFile;
    std::cout << "Enter the absolute path to the text file: ";
    std::cin >> pathFile;
    int counter = 0;

    text.open(pathFile);
    if (text.is_open()) {
        while (!text.eof()) {
            text >> word;
            std::cout << word << " ";
        }
    }
    else std::cout << "File is not open!!!" << std::endl;

    text.close();
    return 0;
}