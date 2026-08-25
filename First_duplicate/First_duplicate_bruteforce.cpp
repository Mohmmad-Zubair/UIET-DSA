#include <iostream>
#include <vector>

int main() {
    int totalLen;
    std::cout << "Enter size of array :";
    std::cin >> totalLen;

    std::vector<int> valList(totalLen);

    std::cout << "Enter the Elements in array :";
    int readIdx = 0;
    while (readIdx < totalLen) {
        std::cin >> valList[readIdx];
        readIdx++;
    }

    int dupIndex = -1;
    bool hasDuplicate = false;

    for (int outer = 1; outer < totalLen; outer++) {
        for (int inner = 0; inner < outer; inner++) {
            if (valList[outer] == valList[inner]) {
                dupIndex = outer;
                hasDuplicate = true;
                break;
            }
        }
    }

    if (hasDuplicate) {
        std::cout << dupIndex + 1 << "th position";
    } else {
        std::cout << -1;
    }

    return 0;
}