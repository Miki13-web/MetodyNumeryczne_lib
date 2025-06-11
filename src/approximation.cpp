#include "../include/approximation.h"
#include "../include/lineq.h"
#include <cmath>

namespace numlib {

    // Pomocnicza funkcja do ca³kowania dla aproksymacji
    double integrate(std::function<double(double)> f, double a, double b, int n = 1000) {
        double h = (b - a) / n;
        double sum = 0.5 * (f(a) + f(b));
        for (int i = 1; i < n; ++i) {
            sum += f(a + i * h);
        }
        return h * sum;
    }

    std::vector<double> least_squares_approximation(std::function<double(double)> f, int degree, double a, double b) {
        int n = degree + 1;
        std::vector<std::vector<double>> A(n, std::vector<double>(n));
        std::vector<double> B(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                auto g = [i, j](double x) { return std::pow(x, i + j); };
                A[i][j] = integrate(g, a, b);
            }
            auto h = [f, i](double x) { return f(x) * std::pow(x, i); };
            B[i] = integrate(h, a, b);
        }

        return gauss_elimination(A, B);
    }

    double evaluate_polynomial(const std::vector<double>& coeffs, double x) {
        double result = 0.0;
        for (size_t i = 0; i < coeffs.size(); ++i) {
            result += coeffs[i] * std::pow(x, i);
        }
        return result;
    }

} // namespace numlib