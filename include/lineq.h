#ifndef LINEQ_H
#define LINEQ_H

#include <vector>

namespace numlib {

	std::vector<double> gauss_elimination(std::vector<std::vector<double>>& A, std::vector<double>& b);

} // namespace numlib

#endif // LINEQ_H