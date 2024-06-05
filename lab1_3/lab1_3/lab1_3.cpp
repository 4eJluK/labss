#include <iostream>
#include <vector>
#include <string>
#include <clocale>

void selectionSort(std::vector<std::string>& phones) {
    int n = phones.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (phones[j] < phones[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(phones[i], phones[minIndex]);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::vector<std::string> phones = { "23-45-67", "12-34-56", "98-76-54", "56-78-90", "11-22-33" };

    std::cout << "Список телефонов до сортировки: " << std::endl;
    for (const std::string& phone : phones) {
        std::cout << phone << std::endl;
    }

    selectionSort(phones);

    std::cout << "\nСписок телефонов после сортировки: " << std::endl;
    for (const std::string& phone : phones) {
        std::cout << phone << std::endl;
    }

    return 0;
}
