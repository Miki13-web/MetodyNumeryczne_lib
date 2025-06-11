#include "../include/numlib.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "== Przyk³ad: Interpolacja wielomianowa Lagrange'a ==" << std::endl;

    // Zbiór danych (wêz³ów) np. z pomiarów
    std::vector<std::pair<double, double>> nodes = {
        {0.0, 0.0},
        {1.0, 0.841471}, // sin(1)
        {2.0, 0.909297}, // sin(2)
        {3.0, 0.141120}  // sin(3)
    };

    std::cout << "\nDane wêz³y interpolacji (z funkcji sin(x)):" << std::endl;
    for (const auto& node : nodes) {
        std::cout << "  x = " << node.first << ", y = " << node.second << std::endl;
    }

    double x_interp = 1.5; // Punkt, w którym chcemy oszacowaæ wartoœæ

    double y_interp = numlib::lagrange_interpolation(nodes, x_interp);

    std::cout << "\nWartoœæ interpolowana w punkcie x = " << x_interp << " wynosi y = " << y_interp << std::endl;
    std::cout << "Prawdziwa wartoœæ sin(" << x_interp << ") = " << std::sin(x_interp) << std::endl;

    return 0;
}