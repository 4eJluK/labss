#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
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
        num = 2 + std::rand() % 102;
    }

    std::cout << "Массив до сортировки: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    selectionSort(arr);

    std::cout << "Массив после сортировки: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
