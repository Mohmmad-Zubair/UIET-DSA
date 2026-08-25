#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int inputSize;
    std::cout << "Enter size of Input array: ";
    std::cin >> inputSize;

    std::vector<int> elementsBuffer(inputSize);

    for (int k = 0; k < inputSize; k++) {
        std::cin >> elementsBuffer[k];
    }

    std::unordered_map<int, int> frequencyMap;

    for (int k = 0; k < inputSize; k++) {
        frequencyMap[elementsBuffer[k]]++;

        if (frequencyMap[elementsBuffer[k]] == 2) {
            std::cout << "First duplicate element: " << elementsBuffer[k];
            return 0;
        }
    }

    std::cout << "No duplicate is present";
    return 0;
}