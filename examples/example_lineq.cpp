#include "../include/numlib.h"
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "== Przyk³ad: Rozwi¹zywanie uk³adu równañ liniowych Ax = b ==" << std::endl;

    std::vector<std::vector<double>> A = {
        {4.0, -2.0,  1.0},
        {1.0, -3.0,  2.0},
        {-1.0, 2.0,  6.0}
    };
    std::vector<double> b = { 15.0, 20.0, 10.0 };

    std::cout << "\nUk³ad równañ:" << std::endl;
    for (size_t i = 0; i < A.size(); ++i) {
        std::cout << "  ";
        for (size_t j = 0; j < A[i].size(); ++j) {
            std::cout << A[i][j] << "*x" << j + 1 << (j < A[i].size() - 1 ? " + " : " ");
        }
        std::cout << "= " << b[i] << std::endl;
    }

    try {
        std::vector<double> x = numlib::gauss_elimination(A, b);

        std::cout << "\nRozwi¹zanie:" << std::endl;
        for (size_t i = 0; i < x.size(); ++i) {
            std::cout << "  x" << i + 1 << " = " << x[i] << std::endl;
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "B³¹d: " << e.what() << std::endl;
    }

    return 0;
}