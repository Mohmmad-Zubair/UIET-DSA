#include <iostream>

struct StackNode {
    int elementVal;
    StackNode* link;
};

void pushStackNode(StackNode*& topPtr, int num) {
    StackNode* freshNode = new StackNode;

    freshNode->elementVal = num;
    freshNode->link = topPtr;

    topPtr = freshNode;
}

void popStackNode(StackNode*& topPtr) {
    if (topPtr == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    StackNode* dummy = topPtr;
    topPtr = topPtr->link;

    delete dummy;
}

bool checkStackEmpty(const StackNode* topPtr) {
    return topPtr == nullptr;
}

void outputStack(const StackNode* topPtr) {
    const StackNode* curr = topPtr;

    while (curr != nullptr) {
        std::cout << curr->elementVal << " ";
        curr = curr->link;
    }

    std::cout << std::endl;
}

int main() {
    StackNode* topPtr = nullptr;

    pushStackNode(topPtr, 10);
    pushStackNode(topPtr, 20);
    pushStackNode(topPtr, 30);

    outputStack(topPtr);

    popStackNode(topPtr);

    outputStack(topPtr);

    if (checkStackEmpty(topPtr)) {
        std::cout << "List is empty";
    } else {
        std::cout << "List is not empty";
    }

    return 0;
}
