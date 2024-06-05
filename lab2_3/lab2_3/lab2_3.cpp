#include <iostream>

int sumOfDigits(int N) {
    if (N == 0) {
        return 0;
    }
    return (N % 10) + sumOfDigits(N / 10);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int N;
    std::cout << "Введите натуральное число N: ";
    std::cin >> N;
    std::cout << "Сумма цифр числа " << N << " равна " << sumOfDigits(N) << std::endl;
    return 0;
}
