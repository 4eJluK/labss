#include <iostream>
#include <vector>
#include <algorithm>

struct Box {
    int weight;
    int capacity;
};

// Компаратор для сортировки коробок
bool compareBoxes(const Box& a, const Box& b) {
    return a.capacity < b.capacity;
}

int main() {
    std::setlocale(LC_ALL, "Russian");

    int n;
    std::cin >> n;

    std::vector<Box> boxes(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> boxes[i].weight >> boxes[i].capacity;
    }

    // Сортируем коробки по их допустимому весу
    std::sort(boxes.begin(), boxes.end(), compareBoxes);

    int count = 0;
    long long currentWeight = 0;

    // Идем по отсортированным коробкам и складываем их одну на другую
    for (const auto& box : boxes) {
        if (currentWeight <= box.capacity) {
            currentWeight += box.weight;
            ++count;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
