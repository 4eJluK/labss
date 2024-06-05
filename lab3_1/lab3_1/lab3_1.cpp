#include <iostream>
#include <cstdlib>
#include <ctime>

void quicksort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) quicksort(arr, left, j);
    if (i < right) quicksort(arr, i, right);
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int size = 1000;
    int arr[size];

    srand(time(0));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1001;
    }

    quicksort(arr, 0, size - 1);

    std::cout << "Отсортированный массив:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
