#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <vector>
#include <functional>

namespace numlib {

	double rectangle_rule(std::function<double(double)> f, double a, double b, int n);
	double trapezoidal_rule(std::function<double(double)> f, double a, double b, int n);
	double simpson_rule(std::function<double(double)> f, double a, double b, int n);

} // namespace numlib

#endif // INTEGRATION_H