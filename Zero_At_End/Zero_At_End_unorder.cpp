#include <iostream>
#include <vector>
#include <utility>

int main() {
    int totalElements;
    std::cout << "Enter size of array :";
    std::cin >> totalElements;

    std::vector<int> elementsVec(totalElements);

    std::cout << "Enter the Elements in array :";
    for (int k = 0; k < totalElements; k++) {
        std::cin >> elementsVec[k];
    }

    int leftPointer = 0;
    int rightPointer = totalElements - 1;

    while (leftPointer < rightPointer) {
        if (elementsVec[leftPointer] == 0 && elementsVec[rightPointer] != 0) {
            std::swap(elementsVec[leftPointer], elementsVec[rightPointer]);
            leftPointer++;
            rightPointer--;
        } else if (elementsVec[leftPointer] != 0) {
            leftPointer++;
        } else {
            rightPointer--;
        }
    }

    std::cout << "Array after moving zeros to the end: ";
    for (int p = 0; p < totalElements; p++) {
        std::cout << elementsVec[p] << " ";
    }

    return 0;
}