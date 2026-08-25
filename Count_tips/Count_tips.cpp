#include <iostream>

int calculateHalvings(float velocity) {
    int halveSteps = 0;
    for (; velocity > 0.00001f; velocity /= 2.0f) {
        halveSteps++;
    }
    return halveSteps;
}

int main() {
    std::cout << calculateHalvings(39.7f);
    return 0;
}