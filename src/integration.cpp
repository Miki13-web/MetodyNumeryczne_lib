#include "../include/integration.h"
#include <stdexcept>

namespace numlib {

    double rectangle_rule(std::function<double(double)> f, double a, double b, int n) {
        if (n <= 0) throw std::invalid_argument("Liczba podprzedzia³ów musi byæ dodatnia.");
        double h = (b - a) / n;
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            sum += f(a + i * h + h / 2.0); // Midpoint rule
        }
        return h * sum;
    }

    double trapezoidal_rule(std::function<double(double)> f, double a, double b, int n) {
        if (n <= 0) throw std::invalid_argument("Liczba podprzedzia³ów musi byæ dodatnia.");
        double h = (b - a) / n;
        double sum = 0.5 * (f(a) + f(b));
        for (int i = 1; i < n; ++i) {
            sum += f(a + i * h);
        }
        return h * sum;
    }

    double simpson_rule(std::function<double(double)> f, double a, double b, int n) {
        if (n <= 0 || n % 2 != 0) throw std::invalid_argument("Liczba podprzedzia³ów musi byæ dodatnia i parzysta.");
        double h = (b - a) / n;
        double sum = f(a) + f(b);
        for (int i = 1; i < n; i += 2) {
            sum += 4 * f(a + i * h);
        }
        for (int i = 2; i < n - 1; i += 2) {
            sum += 2 * f(a + i * h);
        }
        return (h / 3.0) * sum;
    }

} // namespace numlib