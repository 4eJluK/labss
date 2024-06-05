#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <clocale>

void selectionSortDescending(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        std::swap(arr[i], arr[maxIndex]);
    }
}

int main() {
    std::srand(std::time(0)); 

    setlocale(LC_ALL, "Russian");

    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    std::vector<int> arr(size);

    for (int& num : arr) {
        num = std::rand() % 101;
    }

    std::cout << "Массив до сортировки: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    selectionSortDescending(arr);

    std::cout << "Массив после сортировки: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
