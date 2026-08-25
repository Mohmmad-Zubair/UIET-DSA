#include <iostream>

class LNode {
public:
    int infoVal;
    LNode* linkNext;

    LNode(int num) {
        infoVal = num;
        linkNext = nullptr;
    }
};

int main() {
    int listLength;
    std::cout << "Enter the size of Linked List : ";
    std::cin >> listLength;

    LNode* startNode = nullptr;
    LNode* tracer = startNode;

    int itemVal;
    for (int count = 0; count < listLength; count++) {
        std::cin >> itemVal;
        LNode* freshNode = new LNode(itemVal);

        if (!startNode) {
            startNode = freshNode;
            tracer = freshNode;
        } else {
            tracer->linkNext = freshNode;
            tracer = freshNode;
        }
    }

    int selectOption;

    do {
        std::cout << "\n----- MENU -----\n";
        std::cout << "1. Insert Element\n";
        std::cout << "2. Delete Element\n";
        std::cout << "3. Search Element\n";
        std::cout << "4. Display Array\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> selectOption;

        if (selectOption == 1) {
            int element, pos;
            std::cout << "Enter position to insert: ";
            std::cin >> pos;
            tracer = startNode;
            for (int i = 0; tracer != nullptr && i < pos; i++) {
                tracer = tracer->linkNext;
            }
            if (tracer != nullptr) {
                std::cout << "Enter the Element : ";
                std::cin >> element;
                LNode* freshNode = new LNode(element);
                freshNode->linkNext = tracer->linkNext;
                tracer->linkNext = freshNode;
            }
        } else if (selectOption == 2) {
            int pos;
            std::cout << "Enter the Position : ";
            std::cin >> pos;
            tracer = startNode;
            for (int i = 0; tracer != nullptr && i < pos; i++) {
                tracer = tracer->linkNext;
            }
            if (tracer != nullptr && tracer->linkNext != nullptr) {
                LNode* toDelete = tracer->linkNext;
                tracer->linkNext = tracer->linkNext->linkNext;
                delete toDelete;
            }
        } else if (selectOption == 3) {
            int key, loc = 0;
            bool found = false;
            std::cout << "Enter the Element : ";
            std::cin >> key;
            tracer = startNode;
            while (tracer != nullptr) {
                if (tracer->infoVal == key) {
                    std::cout << "Element is present at : " << loc << std::endl;
                    found = true;
                    break;
                }
                tracer = tracer->linkNext;
                loc++;
            }
            if (!found) {
                std::cout << "Element is not present in the Linked List" << std::endl;
            }
        } else if (selectOption == 4) {
            tracer = startNode;
            while (tracer != nullptr) {
                std::cout << tracer->infoVal << " ";
                tracer = tracer->linkNext;
            }
            std::cout << std::endl;
        } else if (selectOption == 5) {
            std::cout << "Exiting program...\n";
        } else {
            std::cout << "Invalid Choice!\n";
        }

    } while (selectOption != 5);

    return 0;
}