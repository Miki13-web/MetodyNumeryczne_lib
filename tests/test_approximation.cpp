#include "../include/numlib.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

// Funkcja f(x) = x^2 - x + 3
double f_poly(double x) {
    return x * x - x + 3.0;
}

void run_approximation_tests() {
    std::cout << "Running approximation tests..." << std::endl;
    const double eps = 1e-6;

    // --- Test 1: Aproksymacja funkcji kwadratowej wielomianem st. 2 ---
    // Oczekiwane wspó³czynniki [3, -1, 1]
    std::vector<double> coeffs = numlib::least_squares_approximation(f_poly, 2, -5.0, 5.0);

    assert(coeffs.size() == 3);
    assert(std::abs(coeffs[0] - 3.0) < eps);
    assert(std::abs(coeffs[1] - (-1.0)) < eps);
    assert(std::abs(coeffs[2] - 1.0) < eps);
    std::cout << "  [PASS] Approximation - correct quadratic case" << std::endl;

    // --- Test 2: Obliczanie wartoœci wielomianu ---
    double val = numlib::evaluate_polynomial(coeffs, 2.0); // f_poly(2) = 4 - 2 + 3 = 5
    assert(std::abs(val - 5.0) < eps);
    std::cout << "  [PASS] Polynomial evaluation" << std::endl;

    std::cout << "Approximation tests finished.\n" << std::endl;
}

int main() {
    run_approximation_tests();
    return 0;
}