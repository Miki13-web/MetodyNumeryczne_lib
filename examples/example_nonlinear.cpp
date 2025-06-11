#include "../include/numlib.h"
#include <iostream>
#include <cmath>
#include <iomanip>

// Funkcja f(x) = cos(x) - x
double my_func(double x) {
    return std::cos(x) - x;
}

// Pochodna f'(x) = -sin(x) - 1
double my_func_derivative(double x) {
    return -std::sin(x) - 1.0;
}

int main() {
    std::cout << std::fixed << std::setprecision(8);
    std::cout << "== Przyk³ad: Rozwi¹zywanie równania nieliniowego cos(x) - x = 0 ==" << std::endl;

    double a = 0.0, b = 1.0;

    std::cout << "\n1. Metoda bisekcji w przedziale [" << a << ", " << b << "]" << std::endl;
    double root_b = numlib::bisection(my_func, a, b);
    std::cout << "   Znalezione miejsce zerowe: " << root_b << std::endl;
    std::cout << "   Wartoœæ funkcji f(" << root_b << ") = " << my_func(root_b) << std::endl;

    double x0 = 0.5;
    std::cout << "\n2. Metoda Newtona z punktem startowym x0 = " << x0 << std::endl;
    double root_n = numlib::newton(my_func, my_func_derivative, x0);
    std::cout << "   Znalezione miejsce zerowe: " << root_n << std::endl;
    std::cout << "   Wartoœæ funkcji f(" << root_n << ") = " << my_func(root_n) << std::endl;

    return 0;
}