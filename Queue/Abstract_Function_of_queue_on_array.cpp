#include <iostream>
#include <queue>

void enqueueItem(std::queue<int>& queueRef, int itemVal) {
    queueRef.push(itemVal);
}

void dequeueItem(std::queue<int>& queueRef) {
    if (queueRef.empty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }

    std::cout << "Removed: " << queueRef.front() << std::endl;
    queueRef.pop();
}

bool checkEmpty(const std::queue<int>& queueRef) {
    return queueRef.empty();
}

int main() {
    std::queue<int> myQueue;

    enqueueItem(myQueue, 10);
    enqueueItem(myQueue, 20);
    enqueueItem(myQueue, 30);

    dequeueItem(myQueue);

    if (checkEmpty(myQueue)) {
        std::cout << "Queue is empty" << std::endl;
    } else {
        std::cout << "Queue is not empty" << std::endl;
    }

    return 0;
}
