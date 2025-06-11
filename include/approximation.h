#ifndef APPROXIMATION_H
#define APPROXIMATION_H

#include <vector>
#include <functional>

namespace numlib {

	std::vector<double> least_squares_approximation(std::function<double(double)> f, int degree, double a, double b);
	double evaluate_polynomial(const std::vector<double>& coeffs, double x);

} // namespace numlib

#endif // APPROXIMATION_H
