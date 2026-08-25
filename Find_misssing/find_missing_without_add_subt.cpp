#include <iostream>
#include <vector>

int main() {
    int sz;
    std::cout << "Enter size of array :";
    std::cin >> sz;

    std::vector<int> numArray(sz);

    std::cout << "Enter the Elements in array :";
    for (int k = 0; k < sz; k++) {
        std::cin >> numArray[k];
    }

    int xorAccumulator = 0;

    for (int val = numArray[0]; val < sz; val++) {
        xorAccumulator ^= val;
    }

    for (int idx = numArray[0]; idx < sz - 1; idx++) {
        xorAccumulator ^= numArray[idx];
    }

    std::cout << "Missing number: " << xorAccumulator;

    return 0;
}
