#include <iostream>
#include <algorithm>

void executeQuickSort(int* items, int leftBound, int rightBound) {
    if (leftBound >= rightBound) return;

    int lPtr = leftBound + 1;
    int rPtr = rightBound;
    int pivotValue = items[leftBound];

    while (lPtr <= rPtr) {
        while (lPtr <= rightBound && items[lPtr] <= pivotValue) {
            lPtr++;
        }
        while (rPtr >= leftBound && items[rPtr] >= pivotValue) {
            rPtr--;
        }
        if (lPtr < rPtr) {
            std::swap(items[lPtr], items[rPtr]);
        }
    }

    std::swap(items[leftBound], items[rPtr]);

    executeQuickSort(items, leftBound, rPtr - 1);
    executeQuickSort(items, rPtr + 1, rightBound);
}

int main() {
    int arrayToSort[8] = {7, 2, 5, 3, 8, 18, 3, 10};

    executeQuickSort(arrayToSort, 0, 7);

    int idx = 0;
    while (idx < 8) {
        std::cout << arrayToSort[idx] << ' ';
        idx++;
    }

    return 0;
}
