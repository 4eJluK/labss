#include <iostream>

void print_prime_factors(int n, int divisor = 2) {
    if (n < 2) {
        return;
    }
    if (n % divisor == 0) {
        std::cout << divisor << " ";
        print_prime_factors(n / divisor, divisor);
    }
    else if (divisor * divisor <= n) {
        print_prime_factors(n, divisor + 1);
    }
    else {
        std::cout << n << " ";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите натуральное число больше 1: ";
    std::cin >> n;
    std::cout << "Простые делители числа " << n << ": ";
    print_prime_factors(n);
    std::cout << std::endl;
    return 0;
}
