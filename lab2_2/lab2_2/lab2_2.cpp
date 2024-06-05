#include <iostream>

void printRange(int A, int B) {
    std::cout << A << " ";
    if (A == B) {
        return;
    }
    if (A < B) {
        printRange(A + 1, B);
    }
    else {
        printRange(A - 1, B);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int A, B;
    std::cout << "Введите число A: ";
    std::cin >> A;
    std::cout << "Введите число B: ";
    std::cin >> B;
    printRange(A, B);
    return 0;
}
