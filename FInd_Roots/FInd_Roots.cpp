#include <iostream>
#include <cmath>

void calculateQuadraticRoots(double coeffA, double coeffB, double coeffC) {
    double discrim = (coeffB * coeffB) - (4.0 * coeffA * coeffC);

    if (discrim == 0.0) {
        double rootFirst = (-coeffB) / (2.0 * coeffA);
        std::cout << "Roots are Real and Equal => " << rootFirst;
    } else if (discrim > 0.0) {
        double rootFirst = ((-coeffB) + std::sqrt(discrim)) / (2.0 * coeffA);
        double rootSecond = ((-coeffB) - std::sqrt(discrim)) / (2.0 * coeffA);
        std::cout << "Roots are Real and DIstinct => " << rootFirst << " , " << rootSecond;
    } else {
        std::cout << "Roots are Imaginary ";
    }
}

int main() {
    calculateQuadraticRoots(1, 8, 12);
    return 0;
}