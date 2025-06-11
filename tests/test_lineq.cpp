#include "../include/numlib.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

void run_lineq_tests() {
    std::cout << "Running linear equation solver tests..." << std::endl;
    const double eps = 1e-7;

    // --- Test 1: Gauss - poprawny przypadek ---
    std::vector<std::vector<double>> A1 = { {2, 1, -1}, {-3, -1, 2}, {-2, 1, 2} };
    std::vector<double> b1 = { 8, -11, -3 };
    std::vector<double> expected_x1 = { 2, 3, -1 };

    std::vector<double> x1 = numlib::gauss_elimination(A1, b1);

    assert(std::abs(x1[0] - expected_x1[0]) < eps);
    assert(std::abs(x1[1] - expected_x1[1]) < eps);
    assert(std::abs(x1[2] - expected_x1[2]) < eps);
    std::cout << "  [PASS] Gauss elimination - correct case" << std::endl;

    // --- Test 2: Gauss - macierz osobliwa ---
    std::vector<std::vector<double>> A2 = { {1, 1, 1}, {2, 2, 2}, {3, 4, 5} };
    std::vector<double> b2 = { 1, 2, 3 };
    bool exception_thrown = false;
    try {
        numlib::gauss_elimination(A2, b2);
    }
    catch (const std::runtime_error& e) {
        exception_thrown = true;
    }
    assert(exception_thrown);
    std::cout << "  [PASS] Gauss elimination - singular matrix" << std::endl;

    std::cout << "Linear equation solver tests finished.\n" << std::endl;
}

int main() {
    run_lineq_tests();
    return 0;
}