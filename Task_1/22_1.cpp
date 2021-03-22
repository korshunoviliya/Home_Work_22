#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream text;
    std::string word;
    std::string searchWord;
    std::cout << "Input the search word: ";
    std::cin >> searchWord;
    int counter = 0;

    text.open("..\\words.txt");
    if (text.is_open()) {
        while (!text.eof()) {
            text >> word;
            if (word == searchWord) counter++;
        }
    }
    else {
        std::cerr << "File is not open!!!" << std::endl;
        return 0;
    }
    std::cin.clear();
    std::cin.ignore();
    std::cout <<  "\nThe word occurs in the text " << counter << " times" << std::endl;
    text.close();
    return 0;
}
