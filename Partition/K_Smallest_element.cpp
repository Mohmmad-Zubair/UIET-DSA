#include <algorithm>
#include <iostream>

int doHoarePartition(int* data, int startIdx, int endIdx) {
    int leftScan = startIdx + 1;
    int rightScan = endIdx;
    int pivotVal = data[startIdx];

    while (leftScan <= rightScan) {
        while (leftScan <= endIdx && data[leftScan] <= pivotVal) {
            leftScan++;
        }
        while (rightScan >= startIdx && data[rightScan] >= pivotVal) {
            rightScan--;
        }
        if (leftScan < rightScan) {
            std::swap(data[leftScan], data[rightScan]);
        }
    }

    std::swap(data[startIdx], data[rightScan]);
    return rightScan;
}

void findKthSmallestSubrange(int* data, int startIdx, int endIdx, int targetRank) {
    int pivotPos = doHoarePartition(data, startIdx, endIdx);

    if (pivotPos == targetRank - 1) {
        for (int idx = 0; idx < targetRank; idx++) {
            std::cout << data[idx] << " ";
        }
        return;
    }

    if (pivotPos > targetRank - 1) {
        findKthSmallestSubrange(data, startIdx, pivotPos - 1, targetRank);
    } else {
        findKthSmallestSubrange(data, pivotPos + 1, endIdx, targetRank);
    }
}

int main() {
    int sampleArray[] = {7, 2, 5, 3, 8, 18, 3, 10};
    int totalSize = 8;
    int targetK = 4;

    std::cout << "4 smallest elements: ";
    findKthSmallestSubrange(sampleArray, 0, totalSize - 1, targetK);

    return 0;
}
