#include <iostream>

void solveTowerOfHanoi(int diskCount, int fromPeg, int auxPeg, int toPeg) {
    if (diskCount <= 0) {
        return;
    }

    solveTowerOfHanoi(diskCount - 1, fromPeg, toPeg, auxPeg);
    std::cout << "Move disk " << diskCount << " from rod " << fromPeg
              << " to rod " << toPeg << '\n';
    solveTowerOfHanoi(diskCount - 1, auxPeg, fromPeg, toPeg);
}

int main() {
    int numDisks;

    std::cout << "Enter the number of disks: ";
    std::cin >> numDisks;

    if (numDisks < 0) {
        std::cout << "Number of disks cannot be negative.\n";
        return 1;
    }

    solveTowerOfHanoi(numDisks, 1, 2, 3);
    return 0;
}