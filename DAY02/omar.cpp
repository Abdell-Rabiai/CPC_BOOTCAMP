#include <iostream>
#include <cmath>

double equation(double x, double A, double B, double C) {
    return A * x + B * sin(x) - C;
}

double derivative(double x, double A, double B) {
    return A + B * cos(x);
}

double newton_raphson(double A, double B, double C) {
    double x = 0.0;  // Initial guess
    int max_iterations = 1000;
    double tolerance = 1e-6;

    for (int i = 0; i < max_iterations; ++i) {
        double fx = equation(x, A, B, C);
        if (std::abs(fx) < tolerance) {
            return x;
        }
        x = x - fx / derivative(x, A, B);
    }

    return NAN;  // Method did not converge
}

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        double A, B, C;
        std::cin >> A >> B >> C;
        double result = newton_raphson(A, B, C);
        if (!std::isnan(result)) {
            std::cout << std::fixed;
            std::cout.precision(6);
            std::cout << result << std::endl;
        } else {
            std::cout << "No solution found" << std::endl;
        }
    }

    return 0;
}
