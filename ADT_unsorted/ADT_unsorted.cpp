#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int buffer[100];
    int totalCount = 0;
    int userOp = 0;

    cout << "Enter the number of elements: ";
    cin >> totalCount;

    cout << "Enter the elements of the unordered array:\n";
    int initIdx = 0;
    while (initIdx < totalCount) {
        cin >> buffer[initIdx];
        initIdx++;
    }

    bool keepRunning = true;
    while (keepRunning) {
        cout << "\n----- MENU -----\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Search Element\n";
        cout << "4. Display Array\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> userOp;

        if (userOp == 1) {
            int val, idx;
            cout << "Enter position (0 to " << totalCount << "): ";
            cin >> idx;

            if (idx < 0 || idx > totalCount) {
                cout << "Invalid Position!\n";
            } else {
                cout << "Enter element to insert: ";
                cin >> val;

                for (int shiftIdx = totalCount; shiftIdx > idx; shiftIdx--) {
                    buffer[shiftIdx] = buffer[shiftIdx - 1];
                }
                buffer[idx] = val;
                totalCount++;
                cout << "Element inserted successfully.\n";
            }
        } else if (userOp == 2) {
            if (totalCount == 0) {
                cout << "Array is empty.\n";
            } else {
                int idx;
                cout << "Enter position to delete (0 to " << totalCount - 1 << "): ";
                cin >> idx;

                if (idx < 0 || idx >= totalCount) {
                    cout << "Invalid Position!\n";
                } else {
                    for (int shiftIdx = idx; shiftIdx < totalCount - 1; shiftIdx++) {
                        buffer[shiftIdx] = buffer[shiftIdx + 1];
                    }
                    totalCount--;
                    cout << "Element deleted successfully.\n";
                }
            }
        } else if (userOp == 3) {
            int targetVal;
            bool isFound = false;

            cout << "Enter element to search: ";
            cin >> targetVal;

            for (int searchIdx = 0; searchIdx < totalCount; searchIdx++) {
                if (buffer[searchIdx] == targetVal) {
                    cout << "Element found at index " << searchIdx << ".\n";
                    isFound = true;
                    break;
                }
            }

            if (!isFound) {
                cout << "Element not found.\n";
            }
        } else if (userOp == 4) {
            if (totalCount == 0) {
                cout << "Array is empty.\n";
            } else {
                cout << "Array elements: ";
                for (int printIdx = 0; printIdx < totalCount; printIdx++) {
                    cout << buffer[printIdx] << " ";
                }
                cout << endl;
            }
        } else if (userOp == 5) {
            cout << "Exiting program...\n";
            keepRunning = false;
        } else {
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}