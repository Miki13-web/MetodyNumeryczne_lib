#include "../include/diffeq.h"
#include <stdexcept>

namespace numlib {

    std::vector<std::pair<double, double>> euler_method(
        std::function<double(double, double)> f, double y0, double t0, double t_end, double h) {
        if (h <= 0) throw std::invalid_argument("Krok czasowy musi byæ dodatni.");
        std::vector<std::pair<double, double>> result;
        double y = y0;
        for (double t = t0; t <= t_end; t += h) {
            result.emplace_back(t, y);
            y = y + h * f(t, y);
        }
        return result;
    }

    std::vector<std::pair<double, double>> rk4_method(
        std::function<double(double, double)> f, double y0, double t0, double t_end, double h) {
        if (h <= 0) throw std::invalid_argument("Krok czasowy musi byæ dodatni.");
        std::vector<std::pair<double, double>> result;
        double y = y0;
        for (double t = t0; t <= t_end; t += h) {
            result.emplace_back(t, y);
            double k1 = h * f(t, y);
            double k2 = h * f(t + 0.5 * h, y + 0.5 * k1);
            double k3 = h * f(t + 0.5 * h, y + 0.5 * k2);
            double k4 = h * f(t + h, y + k3);
            y = y + (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
        }
        return result;
    }

} // namespace numlib