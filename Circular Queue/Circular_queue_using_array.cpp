#include <iostream>

const int MAX_CAP = 10;
int ringBuffer[MAX_CAP];
int headIndex = 0;
int tailIndex = 0;
int itemCount = 0;

bool pushCircular(int val) {
    if (itemCount == MAX_CAP) {
        return false;
    }
    ringBuffer[tailIndex] = val;
    tailIndex = (tailIndex + 1) % MAX_CAP;
    itemCount++;
    return true;
}

bool popCircular(int& poppedVal) {
    if (itemCount == 0) {
        return false;
    }
    poppedVal = ringBuffer[headIndex];
    headIndex = (headIndex + 1) % MAX_CAP;
    itemCount--;
    return true;
}

void showQueue() {
    if (itemCount == 0) {
        std::cout << "Queue is empty.\n";
        return;
    }
    std::cout << "Queue: ";
    for (int offset = 0; offset < itemCount; ++offset) {
        std::cout << ringBuffer[(headIndex + offset) % MAX_CAP] << ' ';
    }
    std::cout << '\n';
}

int main() {
    int userSelect = 0;

    while (userSelect != 4) {
        std::cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> userSelect;

        if (userSelect == 1) {
            int inputVal;
            std::cout << "Enter the element: ";
            std::cin >> inputVal;
            if (!pushCircular(inputVal)) {
                std::cout << "Queue is full.\n";
            }
        } else if (userSelect == 2) {
            int poppedVal;
            if (popCircular(poppedVal)) {
                std::cout << "Dequeued element: " << poppedVal << '\n';
            } else {
                std::cout << "Queue is empty.\n";
            }
        } else if (userSelect == 3) {
            showQueue();
        } else if (userSelect != 4) {
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}