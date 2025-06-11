#ifndef DIFFEEQ_H
#define DIFFEEQ_H

#include <vector>
#include <functional>
#include <utility>

namespace numlib {

	std::vector<std::pair<double, double>> euler_method(std::function<double(double, double)> f, double y0, double t0, double t_end, double h);
	std::vector<std::pair<double, double>> rk4_method(std::function<double(double, double)> f, double y0, double t0, double t_end, double h);

} // namespace numlib

#endif // DIFFEEQ_H
