#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;

vector<int> processNumbers(const vector<int>& input) {
    unordered_set<int> numbers;
    for (int num : input) {
        if (num == 0) {
            break;
        }
        if (num > 0) {
            numbers.insert(num);
        }
        else {
            numbers.erase(-num);
        }
    }

    vector<int> sortedNumbers(numbers.begin(), numbers.end());
    sort(sortedNumbers.begin(), sortedNumbers.end());
    return sortedNumbers;
}

int main() {
    setlocale(LC_ALL, "Russian");

    vector<int> input = { 3, 2, 1, 3, 0 };

    vector<int> result = processNumbers(input);

    cout << "Результат: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
