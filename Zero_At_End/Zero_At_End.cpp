#include <iostream>
#include <vector>

int main() {
    int arraySize;

    std::cout << "Enter size of array: ";
    std::cin >> arraySize;

    std::vector<int> valuesVec(arraySize);

    std::cout << "Enter array elements: ";
    for (int k = 0; k < arraySize; k++) {
        std::cin >> valuesVec[k];
    }

    int nonZeroWritePos = 0;

    for (int scanIdx = 0; scanIdx < arraySize; scanIdx++) {
        if (valuesVec[scanIdx] != 0) {
            valuesVec[nonZeroWritePos] = valuesVec[scanIdx];
            nonZeroWritePos++;
        }
    }

    while (nonZeroWritePos < arraySize) {
        valuesVec[nonZeroWritePos] = 0;
        nonZeroWritePos++;
    }

    std::cout << "Array after moving zeros to the end: ";
    for (int printIdx = 0; printIdx < arraySize; printIdx++) {
        std::cout << valuesVec[printIdx] << " ";
    }

    return 0;
}