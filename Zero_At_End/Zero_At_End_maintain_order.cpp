#include <iostream>
#include <vector>
#include <utility>

int main() {
    int sizeVal;
    std::cout << "Enter size of array :";
    std::cin >> sizeVal;

    std::vector<int> dataVec(sizeVal);

    std::cout << "Enter the Elements in array :";
    for (int k = 0; k < sizeVal; k++) {
        std::cin >> dataVec[k];
    }

    for (int outerIdx = 0; outerIdx < sizeVal; outerIdx++) {
        if (dataVec[outerIdx] == 0) {
            for (int innerIdx = outerIdx + 1; innerIdx < sizeVal; innerIdx++) {
                if (dataVec[innerIdx] != 0) {
                    std::swap(dataVec[outerIdx], dataVec[innerIdx]);
                    break;
                }
            }
        }

        std::cout << "Array after moving zeros to the end: ";
        for (int p = 0; p < sizeVal; p++) {
            std::cout << dataVec[p] << " ";
        }
    }

    return 0;
}