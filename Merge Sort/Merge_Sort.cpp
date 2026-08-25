#include <iostream>
#include <vector>

void combineSubarrays(int* dataArray, int lowIdx, int midIdx, int highIdx) {
    int leftPtr = lowIdx;
    int rightPtr = midIdx + 1;
    int tempIdx = 0;

    std::vector<int> buffer(highIdx - lowIdx + 1);

    while (leftPtr <= midIdx && rightPtr <= highIdx) {
        if (dataArray[leftPtr] <= dataArray[rightPtr]) {
            buffer[tempIdx++] = dataArray[leftPtr++];
        } else {
            buffer[tempIdx++] = dataArray[rightPtr++];
        }
    }

    while (leftPtr <= midIdx) {
        buffer[tempIdx++] = dataArray[leftPtr++];
    }

    while (rightPtr <= highIdx) {
        buffer[tempIdx++] = dataArray[rightPtr++];
    }

    for (int p = lowIdx, q = 0; p <= highIdx; p++, q++) {
        dataArray[p] = buffer[q];
    }
}

void sortViaMerge(int* dataArray, int lowIdx, int highIdx) {
    if (lowIdx < highIdx) {
        int midIdx = lowIdx + (highIdx - lowIdx) / 2;

        sortViaMerge(dataArray, lowIdx, midIdx);
        sortViaMerge(dataArray, midIdx + 1, highIdx);
        combineSubarrays(dataArray, lowIdx, midIdx, highIdx);
    }
}

int main() {
    int rawArray[] = {38, 27, 43, 3, 9, 82, 10};
    int totalLen = sizeof(rawArray) / sizeof(rawArray[0]);

    sortViaMerge(rawArray, 0, totalLen - 1);

    std::cout << "Sorted array: ";

    for (int k = 0; k < totalLen; k++) {
        std::cout << rawArray[k] << " ";
    }
    std::cout << std::endl;

    return 0;
}
