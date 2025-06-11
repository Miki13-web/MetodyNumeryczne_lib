#ifndef NONLINEAR_H
#define NONLINEAR_H

#include <vector>
#include <functional>
#include <string>
#include <utility>

namespace numlib {

	std::vector<std::pair<double, double>> find_brackets(std::function<double(double)> f, double a, double b, double step);
	double bisection(std::function<double(double)> f, double a, double b, double eps = 1e-9, int max_it = 100);
	double newton(std::function<double(double)> f, std::function<double(double)> df, double x0, double eps = 1e-9, int max_it = 100);
	double secant(std::function<double(double)> f, double x0, double x1, double eps = 1e-9, int max_it = 100);

} // namespace numlib

#endif // NONLINEAR_H