#include "../include/numlib.h"
#include <iostream>
#include <cmath>
#include <cassert>

// Funkcja f(x) = 2x, ca³ka na [0, 3] to 9
double f_linear(double x) {
    return 2.0 * x;
}

void run_integration_tests() {
    std::cout << "Running integration tests..." << std::endl;
    const double a = 0.0, b = 3.0;
    const int n = 100;
    const double exact_value = 9.0;
    const double eps = 1e-6;

    // --- Test 1: Metoda trapezów (powinna byæ bardzo dok³adna dla f. liniowej) ---
    double integral_trap = numlib::trapezoidal_rule(f_linear, a, b, n);
    assert(std::abs(integral_trap - exact_value) < eps);
    std::cout << "  [PASS] Trapezoidal rule for linear function" << std::endl;

    // --- Test 2: Metoda Simpsona (powinna byæ dok³adna dla f. liniowej) ---
    double integral_simp = numlib::simpson_rule(f_linear, a, b, n);
    assert(std::abs(integral_simp - exact_value) < eps);
    std::cout << "  [PASS] Simpson's rule for linear function" << std::endl;

    // --- Test 3: B³¹d - nieparzysta liczba przedzia³ów dla Simpsona ---
    bool exception_thrown = false;
    try {
        numlib::simpson_rule(f_linear, a, b, 99);
    }
    catch (const std::invalid_argument& e) {
        exception_thrown = true;
    }
    assert(exception_thrown);
    std::cout << "  [PASS] Simpson's rule with odd intervals" << std::endl;

    std::cout << "Integration tests finished.\n" << std::endl;
}

int main() {
    run_integration_tests();
    return 0;
}