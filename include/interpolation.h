#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <vector>
#include <utility>

namespace numlib {

	double lagrange_interpolation(const std::vector<std::pair<double, double>>& nodes, double x);

} // namespace numlib

#endif // INTERPOLATION_H