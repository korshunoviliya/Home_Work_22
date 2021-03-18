#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string name;
    std::string family;
    double sum;
    std::string paymentDate;
    std::fstream bill;
    double maxSum = 0;
    std::string maxName;
    std::string maxFamily;
    double total = 0;
    bill.open("C:\\Users\\User\\CLionProjects\\22.3\\bill.txt");

    while (!bill.eof()) {
        bill >>  name >> family >> sum >> paymentDate;
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
