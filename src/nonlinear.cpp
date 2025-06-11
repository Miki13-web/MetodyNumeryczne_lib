#include "../include/nonlinear.h"
#include <cmath>
#include <stdexcept>

namespace numlib {

    std::vector<std::pair<double, double>> find_brackets(
        std::function<double(double)> f, double a, double b, double step) {
        std::vector<std::pair<double, double>> brackets;
        double x1 = a;
        double f1 = f(x1);

        for (double x2 = a + step; x2 <= b; x2 += step) {
            double f2 = f(x2);
            if (std::isfinite(f1) && std::isfinite(f2)) {
                if (f1 * f2 <= 0.0) {
                    brackets.emplace_back(x1, x2);
                }
            }
            x1 = x2;
            f1 = f2;
        }
        return brackets;
    }

    double bisection(std::function<double(double)> f, double a, double b, double eps, int max_it) {
        double fa = f(a);
        if (fa * f(b) > 0) return NAN;

        double c = a;
        for (int i = 0; i < max_it; ++i) {
            c = (a + b) / 2.0;
            double fc = f(c);
            if (std::abs(fc) < eps || std::abs(b - a) < eps) {
                return c;
            }
            if (fa * fc < 0) {
                b = c;
            }
            else {
                a = c;
                fa = f(a);
            }
        }
        return c;
    }

    double newton(std::function<double(double)> f, std::function<double(double)> df, double x0, double eps, int max_it) {
        double x = x0;
        for (int i = 0; i < max_it; ++i) {
            double fx = f(x);
            double dfx = df(x);
            if (std::abs(fx) < eps) return x;
            if (std::abs(dfx) < 1e-15) return NAN; // Unikaj dzielenia przez zero

            double x_new = x - fx / dfx;
            if (std::abs(x_new - x) < eps) return x_new;
            x = x_new;
        }
        return x;
    }

    double secant(std::function<double(double)> f, double x0, double x1, double eps, int max_it) {
        double f0 = f(x0);
        double f1 = f(x1);

        for (int i = 0; i < max_it; ++i) {
            if (std::abs(f1) < eps) return x1;
            if (std::abs(f1 - f0) < 1e-15) return NAN;

            double x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
            if (std::abs(x2 - x1) < eps) return x2;

            x0 = x1;
            f0 = f1;
            x1 = x2;
            f1 = f(x1);
        }
        return x1;
    }

} // namespace numlib