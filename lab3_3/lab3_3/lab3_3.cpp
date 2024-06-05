#include <iostream>
#include <cstdlib>
#include <ctime>

const int ROWS = 10;
const int COLS = 5;

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
    int arr[ROWS][COLS];

    srand(time(0));
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            arr[i][j] = rand() % 57 + 5;
        }
    }

    int first_column[ROWS];
    for (int i = 0; i < ROWS; ++i) {
        first_column[i] = arr[i][0];
    }

    quicksort(first_column, 0, ROWS - 1);

    for (int i = 0; i < ROWS; ++i) {
        arr[i][0] = first_column[i];
    }

    std::cout << "Отсортированный массив:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
