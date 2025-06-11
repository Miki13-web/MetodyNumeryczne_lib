#include "../include/interpolation.h"
#include <stdexcept>
#include <cmath>

namespace numlib {

    double lagrange_interpolation(const std::vector<std::pair<double, double>>& nodes, double x) {
        double result = 0.0;
        int n = nodes.size();
        if (n == 0) return 0.0;

        for (int i = 0; i < n; ++i) {
            double basis_polynomial = 1.0;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    if (std::abs(nodes[i].first - nodes[j].first) < 1e-12) {
                        throw std::runtime_error("Punkty wêz³owe x musz¹ byæ unikalne.");
                    }
                    basis_polynomial *= (x - nodes[j].first) / (nodes[i].first - nodes[j].first);
                }
            }
            result += basis_polynomial * nodes[i].second;
        }
        return result;
    }

} // namespace numlib