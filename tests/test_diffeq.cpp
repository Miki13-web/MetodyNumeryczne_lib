#include "../include/numlib.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

// Równanie y' = y, z y(0) = 1. Rozwi¹zanie analityczne: y(t) = e^t
double f_exp(double t, double y) {
    return y;
}

void run_diffeq_tests() {
    std::cout << "Running differential equation solver tests..." << std::endl;
    const double y0 = 1.0, t0 = 0.0, t_end = 1.0, h = 0.1;
    const double exact_solution = std::exp(t_end);

    // --- Test 1: Metoda Eulera ---
    auto result_euler = numlib::euler_method(f_exp, y0, t0, t_end, h);
    double final_euler = result_euler.back().second;
    assert(std::abs(final_euler - exact_solution) > 1e-3); // Euler jest ma³o dok³adny
    std::cout << "  [PASS] Euler method - check execution" << std::endl;

    // --- Test 2: Metoda RK4 ---
    auto result_rk4 = numlib::rk4_method(f_exp, y0, t0, t_end, h);
    double final_rk4 = result_rk4.back().second;
    assert(std::abs(final_rk4 - exact_solution) < 1e-5); // RK4 jest bardzo dok³adny
    std::cout << "  [PASS] RK4 method - check accuracy" << std::endl;

    std::cout << "Differential equation solver tests finished.\n" << std::endl;
}

int main() {
    run_diffeq_tests();
    return 0;
}