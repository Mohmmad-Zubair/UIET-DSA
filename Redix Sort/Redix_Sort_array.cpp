#include <iostream>
#include <queue>

int findPeakValue(const int* data, int count) {
    int peakVal = data[0];
    for (int k = 1; k < count; k++) {
        if (data[k] > peakVal) {
            peakVal = data[k];
        }
    }
    return peakVal;
}

void sortArrayByRadix(int* data, int count) {
    int peakVal = findPeakValue(data, count);

    for (int exponent = 1; peakVal / exponent > 0; exponent *= 10) {
        std::queue<int> bucketsByDigit[10];

        for (int i = 0; i < count; i++) {
            int digitKey = (data[i] / exponent) % 10;
            bucketsByDigit[digitKey].push(data[i]);
        }

        int writeIdx = 0;
        for (int digitKey = 0; digitKey < 10; digitKey++) {
            while (!bucketsByDigit[digitKey].empty()) {
                data[writeIdx++] = bucketsByDigit[digitKey].front();
                bucketsByDigit[digitKey].pop();
            }
        }
    }
}

void outputArrayContents(const int* data, int count) {
    int idx = 0;
    while (idx < count) {
        std::cout << data[idx] << " ";
        idx++;
    }
    std::cout << '\n';
}

int main() {
    int sampleData[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int len = sizeof(sampleData) / sizeof(sampleData[0]);

    std::cout << "Before sorting:\n";
    outputArrayContents(sampleData, len);

    sortArrayByRadix(sampleData, len);

    std::cout << "After sorting:\n";
    outputArrayContents(sampleData, len);

    return 0;
}