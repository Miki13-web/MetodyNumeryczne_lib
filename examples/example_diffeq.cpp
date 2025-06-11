#include "../include/numlib.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

// Równanie logistyczne: y' = r*y*(1 - y/K)
// Modeluje wzrost populacji z ograniczeniem pojemnoœci œrodowiska
const double r = 0.5; // wskaŸnik wzrostu
const double K = 100.0; // pojemnoœæ œrodowiska

double logistic_growth(double t, double y) {
    return r * y * (1.0 - y / K);
}

int main() {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "== Przyk³ad: Rozwi¹zywanie równania logistycznego y' = r*y*(1 - y/K) ==" << std::endl;

    double y0 = 10.0;  // Populacja pocz¹tkowa
    double t0 = 0.0;
    double t_end = 20.0;
    double h = 1.0;     // Krok czasowy

    std::cout << "\nParametry: r=" << r << ", K=" << K << ", y(0)=" << y0 << std::endl;

    auto solution_rk4 = numlib::rk4_method(logistic_growth, y0, t0, t_end, h);

    std::cout << "\nWyniki (metoda RK4):" << std::endl;
    std::cout << "  Czas (t) | Populacja (y)" << std::endl;
    std::cout << "----------------------------" << std::endl;
    for (const auto& point : solution_rk4) {
        std::cout << std::setw(10) << point.first << " | " << std::setw(13) << point.second << std::endl;
    }

    return 0;
}