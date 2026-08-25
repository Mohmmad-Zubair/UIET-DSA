#include <iostream>
#include <cmath>

void computeProjectileMetrics(float initialSpeed, float launchAngleDeg) {
    const float GRAVITY = 9.8f;
    const float PI = 3.14159265f;
    float angleInRadians = launchAngleDeg * (PI / 180.0f);

    float maxHeight = (initialSpeed * initialSpeed * std::sin(angleInRadians) * std::sin(angleInRadians)) / GRAVITY;
    float maxRange = (initialSpeed * initialSpeed * std::sin(2.0f * angleInRadians)) / GRAVITY;

    std::cout << "Maximum height reached => " << maxHeight << std::endl;
    std::cout << "Maximum range reached => " << maxRange;
}

int main() {
    computeProjectileMetrics(15.0f, 30.0f);
    return 0;
}