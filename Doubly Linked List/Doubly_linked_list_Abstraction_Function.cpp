#include <iostream>

struct DNode {
    int val;
    DNode* prevPtr;
    DNode* nextPtr;
};

DNode* listHead = nullptr;

void addAtIdx(int item, int targetIdx) {
    DNode* fresh = new DNode{item, nullptr, nullptr};

    if (targetIdx == 0) {
        fresh->nextPtr = listHead;
        if (listHead != nullptr) {
            listHead->prevPtr = fresh;
        }
        listHead = fresh;
        return;
    }

    DNode* ptr = listHead;
    int currIdx = 0;
    while (ptr != nullptr && currIdx < targetIdx - 1) {
        ptr = ptr->nextPtr;
        currIdx++;
    }

    if (ptr == nullptr) {
        delete fresh;
        std::cout << "Invalid position.\n";
        return;
    }

    fresh->nextPtr = ptr->nextPtr;
    fresh->prevPtr = ptr;

    if (ptr->nextPtr != nullptr) {
        ptr->nextPtr->prevPtr = fresh;
    }
    ptr->nextPtr = fresh;
}

bool removeAtIdx(int targetIdx, int& poppedVal) {
    DNode* ptr = listHead;
    int currIdx = 0;

    while (ptr != nullptr && currIdx < targetIdx) {
        ptr = ptr->nextPtr;
        currIdx++;
    }

    if (ptr == nullptr) {
        return false;
    }

    poppedVal = ptr->val;

    if (ptr->prevPtr != nullptr) {
        ptr->prevPtr->nextPtr = ptr->nextPtr;
    } else {
        listHead = ptr->nextPtr;
    }

    if (ptr->nextPtr != nullptr) {
        ptr->nextPtr->prevPtr = ptr->prevPtr;
    }

    delete ptr;
    return true;
}

void findValue(int targetKey) {
    DNode* ptr = listHead;
    int loc = 0;

    while (ptr != nullptr) {
        if (ptr->val == targetKey) {
            std::cout << "Element found at position " << loc << ".\n";
            return;
        }
        ptr = ptr->nextPtr;
        loc++;
    }

    std::cout << "Element not found.\n";
}

void outputList() {
    DNode* ptr = listHead;

    if (ptr == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }

    std::cout << "List: ";
    while (ptr != nullptr) {
        std::cout << ptr->val << ' ';
        ptr = ptr->nextPtr;
    }
    std::cout << '\n';
}

int main() {
    int userChoice = 0;

    do {
        std::cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> userChoice;

        if (userChoice == 1) {
            int val, pos;
            std::cout << "Enter element and position: ";
            std::cin >> val >> pos;
            if (pos < 0) {
                std::cout << "Invalid position.\n";
            } else {
                addAtIdx(val, pos);
            }
        } else if (userChoice == 2) {
            int pos, removed;
            std::cout << "Enter position: ";
            std::cin >> pos;
            if (pos < 0 || !removeAtIdx(pos, removed)) {
                std::cout << "Invalid position.\n";
            } else {
                std::cout << "Deleted element: " << removed << '\n';
            }
        } else if (userChoice == 3) {
            int key;
            std::cout << "Enter element: ";
            std::cin >> key;
            findValue(key);
        } else if (userChoice == 4) {
            outputList();
        } else if (userChoice != 5) {
            std::cout << "Invalid choice.\n";
        }
    } while (userChoice != 5);

    return 0;
}
