#include <iostream>
#include <algorithm>

void rearrangeAroundPivot(int* values, int lowerIndex, int upperIndex) {
    int leftMarker = lowerIndex + 1;
    int rightMarker = upperIndex;
    int pivotItem = values[lowerIndex];

    while (leftMarker <= rightMarker) {
        while (leftMarker <= upperIndex && values[leftMarker] <= pivotItem) {
            leftMarker++;
        }
        while (rightMarker >= lowerIndex && values[rightMarker] >= pivotItem) {
            rightMarker--;
        }
        if (leftMarker < rightMarker) {
            std::swap(values[leftMarker], values[rightMarker]);
        }
    }

    std::swap(values[lowerIndex], values[rightMarker]);
}

int main() {
    int numbers[8] = {7, 2, 5, 3, 8, 18, 3, 10};

    rearrangeAroundPivot(numbers, 0, 7);

    for (int k = 0; k < 8; k++) {
        std::cout << numbers[k] << ' ';
    }

    return 0;
}
