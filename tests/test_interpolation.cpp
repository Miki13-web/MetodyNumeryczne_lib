#include "../include/numlib.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

void run_interpolation_tests() {
    std::cout << "Running interpolation tests..." << std::endl;
    const double eps = 1e-9;

    // Wêz³y z funkcji y = x^2: (0,0), (1,1), (2,4)
    std::vector<std::pair<double, double>> nodes = { {0.0, 0.0}, {1.0, 1.0}, {2.0, 4.0} };

    // --- Test 1: Interpolacja w punkcie, który jest wêz³em ---
    double val1 = numlib::lagrange_interpolation(nodes, 1.0);
    assert(std::abs(val1 - 1.0) < eps);
    std::cout << "  [PASS] Lagrange interpolation at a node" << std::endl;

    // --- Test 2: Interpolacja w punkcie pomiêdzy wêz³ami ---
    double val2 = numlib::lagrange_interpolation(nodes, 1.5);
    assert(std::abs(val2 - 2.25) < eps); // (1.5)^2 = 2.25
    std::cout << "  [PASS] Lagrange interpolation between nodes" << std::endl;

    // --- Test 3: B³¹d - zduplikowane wêz³y x ---
    std::vector<std::pair<double, double>> bad_nodes = { {0.0, 0.0}, {1.0, 1.0}, {1.0, 5.0} };
    bool exception_thrown = false;
    try {
        numlib::lagrange_interpolation(bad_nodes, 0.5);
    }
    catch (const std::runtime_error& e) {
        exception_thrown = true;
    }
    assert(exception_thrown);
    std::cout << "  [PASS] Lagrange with duplicate nodes" << std::endl;


    std::cout << "Interpolation tests finished.\n" << std::endl;
}

int main() {
    run_interpolation_tests();
    return 0;
}