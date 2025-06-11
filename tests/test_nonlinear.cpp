#include "../include/numlib.h"
#include <iostream>
#include <cmath>
#include <cassert>

// Funkcja testowa f(x) = x^2 - 2, miejsce zerowe w sqrt(2)
double f1(double x) { return x * x - 2.0; }
double df1(double x) { return 2.0 * x; }

void run_nonlinear_tests() {
    std::cout << "Running nonlinear solver tests..." << std::endl;
    const double eps = 1e-7;

    // --- Test 1: Bisection - poprawny przypadek ---
    double root_bisection = numlib::bisection(f1, 1.0, 2.0);
    assert(std::abs(root_bisection - std::sqrt(2.0)) < eps);
    std::cout << "  [PASS] Bisection - correct case" << std::endl;

    // --- Test 2: Bisection - b³êdny przedzia³ ---
    assert(std::isnan(numlib::bisection(f1, 2.0, 3.0)));
    std::cout << "  [PASS] Bisection - bad interval" << std::endl;

    // --- Test 3: Newton - poprawny przypadek ---
    double root_newton = numlib::newton(f1, df1, 1.0);
    assert(std::abs(root_newton - std::sqrt(2.0)) < eps);
    std::cout << "  [PASS] Newton - correct case" << std::endl;

    // --- Test 4: Newton - pochodna bliska zeru (dla x=0) ---
    // f(x) = x^2 + 2, df(0)=0
    assert(std::isnan(numlib::newton([](double x) {return x * x + 2; }, [](double x) {return 2 * x; }, 0.0)));
    std::cout << "  [PASS] Newton - zero derivative" << std::endl;

    std::cout << "Nonlinear solver tests finished.\n" << std::endl;
}

int main() {
    run_nonlinear_tests();
    return 0;
}