#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int totalElements;
    std::cout << "Enter size of array :";
    std::cin >> totalElements;

    std::vector<int> inputSequence(totalElements);

    std::cout << "Enter the Elements in array :";
    for (int idx = 0; idx < totalElements; ++idx) {
        std::cin >> inputSequence[idx];
    }

    std::unordered_map<int, int> indexTracker;

    for (int idx = 0; idx < totalElements; ++idx) {
        indexTracker[inputSequence[idx]] = idx;
    }

    int firstDupIndex = -1;
    bool duplicateExists = false;

    for (int idx = 0; idx < totalElements; ++idx) {
        if (idx != indexTracker[inputSequence[idx]]) {
            firstDupIndex = indexTracker[inputSequence[idx]];
            duplicateExists = true;
            break;
        }
    }

    if (duplicateExists) {
        std::cout << firstDupIndex + 1 << "th position";
    } else {
        std::cout << -1;
    }

    return 0;
}