#include <iostream>

struct QueueNode {
    int info;
    QueueNode* nextPtr;
};

QueueNode* tailPtr = nullptr;

void insertCQ(int val) {
    QueueNode* freshNode = new QueueNode{val, nullptr};
    if (!tailPtr) {
        tailPtr = freshNode;
        tailPtr->nextPtr = tailPtr;
    } else {
        freshNode->nextPtr = tailPtr->nextPtr;
        tailPtr->nextPtr = freshNode;
        tailPtr = freshNode;
    }
}

bool removeCQ(int& retrievedVal) {
    if (!tailPtr) {
        return false;
    }

    QueueNode* headPtr = tailPtr->nextPtr;
    retrievedVal = headPtr->info;

    if (headPtr == tailPtr) {
        tailPtr = nullptr;
    } else {
        tailPtr->nextPtr = headPtr->nextPtr;
    }

    delete headPtr;
    return true;
}

void printCQ() {
    if (!tailPtr) {
        std::cout << "Queue is empty.\n";
        return;
    }

    QueueNode* runner = tailPtr->nextPtr;
    std::cout << "Queue: ";

    while (true) {
        std::cout << runner->info << ' ';
        runner = runner->nextPtr;
        if (runner == tailPtr->nextPtr) break;
    }

    std::cout << '\n';
}

int main() {
    int menuOption = 0;

    while (menuOption != 4) {
        std::cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> menuOption;

        if (menuOption == 1) {
            int elem;
            std::cout << "Enter the element: ";
            std::cin >> elem;
            insertCQ(elem);
        } else if (menuOption == 2) {
            int elem;
            if (removeCQ(elem)) {
                std::cout << "Dequeued element: " << elem << '\n';
            } else {
                std::cout << "Queue is empty.\n";
            }
        } else if (menuOption == 3) {
            printCQ();
        } else if (menuOption != 4) {
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
