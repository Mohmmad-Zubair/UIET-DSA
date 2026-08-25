#include <iostream>
#include <stack>

void pushElement(std::stack<int>& stackContainer, int val) {
    stackContainer.push(val);
}

void popElement(std::stack<int>& stackContainer) {
    if (stackContainer.empty()) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }

    std::cout << "Popped: " << stackContainer.top() << std::endl;
    stackContainer.pop();
}

bool isStackEmpty(const std::stack<int>& stackContainer) {
    return stackContainer.empty();
}

int main() {
    std::stack<int> stackContainer;

    pushElement(stackContainer, 10);
    pushElement(stackContainer, 20);
    pushElement(stackContainer, 30);

    popElement(stackContainer);

    if (isStackEmpty(stackContainer)) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Stack is not empty" << std::endl;
    }

    return 0;
}
