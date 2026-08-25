#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* nextPtr;

    ListNode(int num) : val(num), nextPtr(nullptr) {}
};

void appendNode(ListNode*& start, int num) {
    ListNode* freshNode = new ListNode(num);
    if (!start) {
        start = freshNode;
        return;
    }
    ListNode* curr = start;
    while (curr->nextPtr != nullptr) {
        curr = curr->nextPtr;
    }
    curr->nextPtr = freshNode;
}

void placeInSortedOrder(ListNode*& bucketRef, ListNode* elem) {
    if (!bucketRef || elem->val < bucketRef->val) {
        elem->nextPtr = bucketRef;
        bucketRef = elem;
        return;
    }
    ListNode* iter = bucketRef;
    while (iter->nextPtr != nullptr && iter->nextPtr->val <= elem->val) {
        iter = iter->nextPtr;
    }
    elem->nextPtr = iter->nextPtr;
    iter->nextPtr = elem;
}

ListNode* sortLinkedListBuckets(ListNode* start) {
    if (!start || !start->nextPtr) return start;

    int smallest = start->val;
    int largest = start->val;
    int elementCount = 0;

    for (ListNode* scan = start; scan != nullptr; scan = scan->nextPtr) {
        if (scan->val < smallest) smallest = scan->val;
        if (scan->val > largest) largest = scan->val;
        elementCount++;
    }

    long long span = static_cast<long long>(largest) - smallest + 1;
    std::vector<ListNode*> bucketBins(elementCount, nullptr);

    while (start != nullptr) {
        ListNode* currNode = start;
        start = start->nextPtr;
        currNode->nextPtr = nullptr;

        long long diff = static_cast<long long>(currNode->val) - smallest;
        int bucketIndex = static_cast<int>((diff * elementCount) / span);
        if (bucketIndex == elementCount) {
            bucketIndex--;
        }

        placeInSortedOrder(bucketBins[bucketIndex], currNode);
    }

    ListNode* resultHead = nullptr;
    ListNode* resultTail = nullptr;

    for (size_t i = 0; i < bucketBins.size(); ++i) {
        ListNode* binHead = bucketBins[i];
        while (binHead != nullptr) {
            ListNode* item = binHead;
            binHead = binHead->nextPtr;

            if (!resultHead) {
                resultHead = item;
                resultTail = item;
            } else {
                resultTail->nextPtr = item;
                resultTail = item;
            }
        }
    }

    return resultHead;
}

void displayList(const ListNode* start) {
    const ListNode* ptr = start;
    while (ptr != nullptr) {
        std::cout << ptr->val << " -> ";
        ptr = ptr->nextPtr;
    }
    std::cout << "NULL\n";
}

void clearList(ListNode* start) {
    while (start != nullptr) {
        ListNode* temp = start;
        start = start->nextPtr;
        delete temp;
    }
}

int main() {
    ListNode* first = nullptr;

    appendNode(first, 42);
    appendNode(first, 32);
    appendNode(first, 33);
    appendNode(first, 52);
    appendNode(first, 37);
    appendNode(first, 47);
    appendNode(first, 51);

    std::cout << "Before sorting:\n";
    displayList(first);

    first = sortLinkedListBuckets(first);

    std::cout << "After sorting:\n";
    displayList(first);

    clearList(first);
    return 0;
}
