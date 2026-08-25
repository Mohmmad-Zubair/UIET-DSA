#include <iostream>

struct QueueElement {
    int content;
    QueueElement* nextLink;
};

void addQueueNode(QueueElement*& headRef, QueueElement*& tailRef, int val) {
    QueueElement* freshNode = new QueueElement{val, nullptr};

    if (tailRef == nullptr) {
        headRef = freshNode;
        tailRef = freshNode;
    } else {
        tailRef->nextLink = freshNode;
        tailRef = freshNode;
    }
}

void removeQueueNode(QueueElement*& headRef, QueueElement*& tailRef) {
    if (headRef == nullptr) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }

    QueueElement* tempNode = headRef;
    std::cout << "Removed: " << headRef->content << std::endl;

    headRef = headRef->nextLink;
    if (headRef == nullptr) {
        tailRef = nullptr;
    }

    delete tempNode;
}

bool isQueueEmpty(const QueueElement* headRef) {
    return headRef == nullptr;
}

void printQueueNodes(const QueueElement* headRef) {
    const QueueElement* runner = headRef;
    while (runner != nullptr) {
        std::cout << runner->content << " ";
        runner = runner->nextLink;
    }
    std::cout << std::endl;
}

int main() {
    QueueElement* headRef = nullptr;
    QueueElement* tailRef = nullptr;

    addQueueNode(headRef, tailRef, 10);
    addQueueNode(headRef, tailRef, 20);
    addQueueNode(headRef, tailRef, 30);

    printQueueNodes(headRef);

    removeQueueNode(headRef, tailRef);

    printQueueNodes(headRef);

    if (isQueueEmpty(headRef)) {
        std::cout << "Queue is empty";
    } else {
        std::cout << "Queue is not empty";
    }

    return 0;
}
