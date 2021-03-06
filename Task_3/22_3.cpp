#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string name;
    std::string family;
    double sum = 0;
    double maxSum = 0;
    std::string maxName;
    std::string maxFamily;
    double total = 0;
    std::string paymentDate;

    std::ifstream bill;

    bill.open("..\\bill.txt");

    if (!bill.is_open()) {
        std::cerr << "File is not open!!!" << std::endl;
        return 1;
    }

    while (!bill.eof()) {
            bill >> name >> family >> sum >> paymentDate;
            total += sum;
            if (maxSum < sum) {
                maxSum = sum;
                maxName = name;
                maxFamily = family;
            }
    }

    bill.close();

    std::cout << "Total: " << total << std::endl;
    std::cout << "Maximum: " << maxName << " " << maxFamily << " " << maxSum;

    return 0;
}
