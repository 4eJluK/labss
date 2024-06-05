#include <iostream>

void printNumbers(int n) {
    if (n == 0) {
        return;
    }
    printNumbers(n - 1);
    std::cout << n << " ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите натуральное число n: ";
    std::cin >> n;
    printNumbers(n);
    return 0;
}
