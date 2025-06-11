#include "../include/numlib.h"
#include <iostream>
#include <cmath>
#include <iomanip>

// Funkcja do ca�kowania f(x) = sin(x)
double my_integrand(double x) {
    return std::sin(x);
}

int main() {
    std::cout << std::fixed << std::setprecision(8);
    std::cout << "== Przyk�ad: Ca�kowanie numeryczne funkcji sin(x) w przedziale [0, PI] ==" << std::endl;

    double a = 0.0;
    double b = M_PI; // PI z cmath
    int n = 100; // Liczba podprzedzia��w

    // Dok�adny wynik to -cos(PI) - (-cos(0)) = 1 - (-1) = 2
    double exact_value = 2.0;

    std::cout << "Dok�adna warto�� ca�ki: " << exact_value << std::endl;

    double integral_rect = numlib::rectangle_rule(my_integrand, a, b, n);
    std::cout << "\nWynik metod� prostok�t�w:   " << integral_rect << std::endl;
    std::cout << "B��d bezwzgl�dny:          " << std::abs(integral_rect - exact_value) << std::endl;

    double integral_trap = numlib::trapezoidal_rule(my_integrand, a, b, n);
    std::cout << "\nWynik metod� trapez�w:      " << integral_trap << std::endl;
    std::cout << "B��d bezwzgl�dny:          " << std::abs(integral_trap - exact_value) << std::endl;

    double integral_simp = numlib::simpson_rule(my_integrand, a, b, n);
    std::cout << "\nWynik metod� Simpsona:      " << integral_simp << std::endl;
    std::cout << "B��d bezwzgl�dny:          " << std::abs(integral_simp - exact_value) << std::endl;

    return 0;
}