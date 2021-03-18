#include <iostream>
#include <fstream>

int spinningDrum(int pointerOffset, int sector, bool busySector[]){
    std::cout << "Enter how much to move the drum: " << std::endl;
    std::cin >> pointerOffset;
    sector += pointerOffset;
    if (sector >= 13) sector -= 13 * (sector / 13);
    while (true) {
        if (!busySector[sector]) {
            busySector[sector] = true;
            return sector;
        } else {
            sector++;
            if (sector == 13) sector = 0;
        }
    }
}

int main() {

    int pointerOffset = 0;
    int sector = 0;
    bool busySector[13] = {false};
    int playerPoints = 0;
    int spectatorPoints = 0;
    std::string pathFile;
    std::string pathFileAnswer;

    while (playerPoints < 6 && spectatorPoints < 6) {
        sector = spinningDrum(pointerOffset, sector, busySector);
        std::cout << "Question number " << sector << std::endl;

        if (sector == 0) {
            pathFile = "..\\question0.txt";
            pathFileAnswer = "..\\answer0.txt";
        } else if (sector == 1) {
            pathFile = "..\\question1.txt";
            pathFileAnswer = "..\\answer1.txt";
        } else if (sector == 2) {
            pathFile = "..\\question2.txt";
            pathFileAnswer = "..\\answer2.txt";
        } else if (sector == 3) {
            pathFile = "..\\question3.txt";
            pathFileAnswer = "..\\answer3.txt";
        } else if (sector == 4) {
            pathFile = "..\\question4.txt";
            pathFileAnswer = "..\\answer4.txt";
        } else if (sector == 5) {
            pathFile = "..\\question5.txt";
            pathFileAnswer = "..\\answer5.txt";
        } else if (sector == 6) {
            pathFile = "..\\question6.txt";
            pathFileAnswer = "..\\answer6.txt";
        } else if (sector == 7) {
            pathFile = "..\\question7.txt";
            pathFileAnswer = "..\\answer7.txt";
        } else if (sector == 8) {
            pathFile = "..\\question8.txt";
            pathFileAnswer = "..\\answer8.txt";
        } else if (sector == 9) {
            pathFile = "..\\question9.txt";
            pathFileAnswer = "..\\answer9.txt";
        } else if (sector == 10) {
            pathFile = "..\\question10.txt";
            pathFileAnswer = "..\\answer10.txt";
        } else if (sector == 11) {
            pathFile = "..\\question11.txt";
            pathFileAnswer = "..\\answer11.txt";
        } else {
            pathFile = "..\\question12.txt";
            pathFileAnswer = "..\\answer12.txt";
        }

        std::string answer;
        std::string question;
        std::ifstream fileQuestion;
        std::ifstream fileAnswer;

        fileQuestion.open(pathFile);
        while (!fileQuestion.eof()) {
            fileQuestion >> question;
            std::cout << question << " ";
        }
        std::string answerPlayer;
        std::cout << "\nInput the answer: ";
        std::cin >> answerPlayer;

        fileAnswer.open(pathFileAnswer);
        fileAnswer >> answer;

        if (answer == answerPlayer) {
            playerPoints++;
            std::cout << "Connoisseurs answered correctly\n";
        } else {
            spectatorPoints++;
            std::cout << "Experts answered incorrectly. \nA point is awarded to the viewer.\n";
        }
        fileQuestion.close();
        fileAnswer.close();
    };

    if (playerPoints == 6) std::cout << "Connoisseurs won!!!\n";
    else std::cout << "TV viewers won!!!\n";

    return 0;
}