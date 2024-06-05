#include <iostream>
#include <cstdlib>
#include <cstring>
#include <locale.h>

int compare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int num_students = 5;
    const char* students[num_students] = {
        "Анвар", "Пупа", "Лупа", "Буба", "Даниил"
    };

    qsort(students, num_students, sizeof(const char*), compare);

    std::cout << "Отсортированный список студентов:\n";
    for (int i = 0; i < num_students; ++i) {
        std::cout << students[i] << "\n";
    }

    return 0;
}
