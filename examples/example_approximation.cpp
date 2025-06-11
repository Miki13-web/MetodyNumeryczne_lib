#include "../include/numlib.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

// Funkcja, któr¹ bêdziemy aproksymowaæ: f(x) = exp(x/2) * sin(2x)
double func_to_approximate(double x) {
    return std::exp(x / 2.0) * std::sin(2.0 * x);
}

int main() {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "== Przyk³ad: Aproksymacja funkcji f(x) = exp(x/2) * sin(2x) ==" << std::endl;

    int degree = 4;
    double a = -1.0, b = 3.0;

    std::cout << "Aproksymujemy na przedziale [" << a << ", " << b << "] wielomianem stopnia " << degree << std::endl;

    std::vector<double> coeffs = numlib::least_squares_approximation(func_to_approximate, degree, a, b);

    std::cout << "\nObliczone wspó³czynniki wielomianu (a0, a1, ...):" << std::endl;
    for (size_t i = 0; i < coeffs.size(); ++i) {
        std::cout << "  a" << i << " = " << coeffs[i] << std::endl;
    }

    std::cout << "\nPorównanie wartoœci w kilku punktach:" << std::endl;
    std::cout << "  x      | f(x)      | Aproksymacja" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    for (double x = a; x <= b; x += 1.0) {
        double y_true = func_to_approximate(x);
        double y_approx = numlib::evaluate_polynomial(coeffs, x);
        std::cout << std::setw(8) << x << " | "
            << std::setw(9) << y_true << " | "
            << std::setw(9) << y_approx << std::endl;
    }

    return 0;
}