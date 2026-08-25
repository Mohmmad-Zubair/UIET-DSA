#include <iostream>
#include <vector>

void insertionSortBucket(std::vector<int>& bucketVec) {
    int bucketLen = static_cast<int>(bucketVec.size());
    for (int p = 1; p < bucketLen; ++p) {
        int keyVal = bucketVec[p];
        int q = p - 1;
        while (q >= 0 && bucketVec[q] > keyVal) {
            bucketVec[q + 1] = bucketVec[q];
            q--;
        }
        bucketVec[q + 1] = keyVal;
    }
}

void executeBucketSort(int* values, int count) {
    if (count <= 1) return;

    int lowerBound = values[0];
    int upperBound = values[0];

    for (int i = 1; i < count; ++i) {
        if (values[i] < lowerBound) lowerBound = values[i];
        if (values[i] > upperBound) upperBound = values[i];
    }

    int numBuckets = upperBound - lowerBound + 1;
    std::vector<std::vector<int>> bucketList(numBuckets);

    for (int i = 0; i < count; ++i) {
        bucketList[values[i] - lowerBound].push_back(values[i]);
    }

    int writePos = 0;
    for (size_t b = 0; b < bucketList.size(); ++b) {
        insertionSortBucket(bucketList[b]);
        for (size_t k = 0; k < bucketList[b].size(); ++k) {
            values[writePos++] = bucketList[b][k];
        }
    }
}

void printSequence(const int* arrayPtr, int total) {
    for (int i = 0; i < total; ++i) {
        std::cout << arrayPtr[i] << " ";
    }
    std::cout << '\n';
}

int main() {
    int numbers[] = {42, 32, 33, 52, 37, 47, 51};
    int len = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Before sorting:\n";
    printSequence(numbers, len);

    executeBucketSort(numbers, len);

    std::cout << "After sorting:\n";
    printSequence(numbers, len);

    return 0;
}
