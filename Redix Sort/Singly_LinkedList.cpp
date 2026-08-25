#include <iostream>
#include <queue>

struct SNode {
    int val;
    SNode* nextPtr;

    SNode(int item) : val(item), nextPtr(nullptr) {}
};

void pushBackNode(SNode*& startNode, int item) {
    SNode* freshNode = new SNode(item);

    if (!startNode) {
        startNode = freshNode;
        return;
    }

    SNode* curr = startNode;
    while (curr->nextPtr != nullptr) {
        curr = curr->nextPtr;
    }
    curr->nextPtr = freshNode;
}

int findMaxInLinkedList(SNode* startNode) {
    int highestVal = startNode->val;
    for (SNode* ptr = startNode; ptr != nullptr; ptr = ptr->nextPtr) {
        if (ptr->val > highestVal) {
            highestVal = ptr->val;
        }
    }
    return highestVal;
}

SNode* sortLinkedListByRadix(SNode* startNode) {
    if (!startNode || !startNode->nextPtr) return startNode;

    int highestVal = findMaxInLinkedList(startNode);

    for (int radixPos = 1; highestVal / radixPos > 0; radixPos *= 10) {
        std::queue<SNode*> digitBins[10];
        SNode* tracer = startNode;

        while (tracer != nullptr) {
            SNode* upcoming = tracer->nextPtr;
            tracer->nextPtr = nullptr;

            int bucketIdx = (tracer->val / radixPos) % 10;
            digitBins[bucketIdx].push(tracer);
            tracer = upcoming;
        }

        startNode = nullptr;
        SNode* lastNode = nullptr;

        for (int bucketIdx = 0; bucketIdx < 10; bucketIdx++) {
            while (!digitBins[bucketIdx].empty()) {
                SNode* elem = digitBins[bucketIdx].front();
                digitBins[bucketIdx].pop();

                if (!startNode) {
                    startNode = elem;
                    lastNode = elem;
                } else {
                    lastNode->nextPtr = elem;
                    lastNode = elem;
                }
            }
        }
    }

    return startNode;
}

void printLinkedListNodes(const SNode* startNode) {
    const SNode* ptr = startNode;
    while (ptr != nullptr) {
        std::cout << ptr->val << " -> ";
        ptr = ptr->nextPtr;
    }
    std::cout << "NULL\n";
}

int main() {
    SNode* firstNode = nullptr;

    pushBackNode(firstNode, 170);
    pushBackNode(firstNode, 45);
    pushBackNode(firstNode, 75);
    pushBackNode(firstNode, 90);
    pushBackNode(firstNode, 802);
    pushBackNode(firstNode, 24);
    pushBackNode(firstNode, 2);
    pushBackNode(firstNode, 66);

    std::cout << "Before sorting:\n";
    printLinkedListNodes(firstNode);

    firstNode = sortLinkedListByRadix(firstNode);

    std::cout << "After sorting:\n";
    printLinkedListNodes(firstNode);

    return 0;
}