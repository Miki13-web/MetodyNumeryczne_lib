#include "../include/lineq.h"
#include <cmath>
#include <stdexcept>
#include <algorithm> // Dla std::swap

namespace numlib {

    std::vector<double> gauss_elimination(std::vector<std::vector<double>>& A, std::vector<double>& b) {
        int n = b.size();
        for (int i = 0; i < n; ++i) {
            int max_row = i;
            for (int k = i + 1; k < n; ++k) {
                if (std::abs(A[k][i]) > std::abs(A[max_row][i])) {
                    max_row = k;
                }
            }
            std::swap(A[i], A[max_row]);
            std::swap(b[i], b[max_row]);

            if (std::abs(A[i][i]) < 1e-12) {
                throw std::runtime_error("Macierz jest osobliwa.");
            }

            for (int k = i + 1; k < n; ++k) {
                double c = A[k][i] / A[i][i];
                for (int j = i; j < n; ++j) {
                    A[k][j] -= c * A[i][j];
                }
                b[k] -= c * b[i];
            }
        }

        std::vector<double> x(n);
        for (int i = n - 1; i >= 0; --i) {
            x[i] = b[i];
            for (int j = i + 1; j < n; ++j) {
                x[i] -= A[i][j] * x[j];
            }
            x[i] /= A[i][i];
        }
        return x;
    }

} // namespace numlib