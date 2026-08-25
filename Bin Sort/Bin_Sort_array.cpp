#include <iostream>
#include <vector>

void displayElements(const int* dataPtr, int count) {
    int pos = 0;
    while (pos < count) {
        std::cout << dataPtr[pos] << " ";
        pos++;
    }
    std::cout << '\n';
}

void performBinSort(int* items, int numItems) {
    if (numItems <= 1) return;

    int minVal = items[0];
    int maxVal = items[0];

    for (int k = 1; k < numItems; ++k) {
        if (items[k] < minVal) minVal = items[k];
        if (items[k] > maxVal) maxVal = items[k];
    }

    int rangeSize = maxVal - minVal + 1;
    std::vector<int> bucketCounts(rangeSize, 0);

    for (int k = 0; k < numItems; ++k) {
        bucketCounts[items[k] - minVal]++;
    }

    int writeIdx = 0;
    for (size_t offset = 0; offset < bucketCounts.size(); offset++) {
        while (bucketCounts[offset] > 0) {
            items[writeIdx++] = static_cast<int>(offset) + minVal;
            bucketCounts[offset]--;
        }
    }
}

int main() {
    int inputData[] = {42, 32, 33, 52, 37, 47, 51};
    int len = sizeof(inputData) / sizeof(inputData[0]);

    std::cout << "Before sorting:\n";
    displayElements(inputData, len);

    performBinSort(inputData, len);

    std::cout << "After sorting:\n";
    displayElements(inputData, len);

    return 0;
}
