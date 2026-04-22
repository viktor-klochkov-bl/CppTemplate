#pragma once

#include <vector>

namespace lib_stats {

// Returns the sum of all elements in the vector
double sum(std::vector<double> values);

// Returns the average of all elements in the vector
double average(std::vector<double> values);

// Returns the maximum element in the vector
double max(std::vector<double> values);

// Returns the minimum element in the vector
double min(std::vector<double> values);

// Returns only elements greater than threshold
std::vector<double> filter_greater_than(std::vector<double> values, double threshold);

}
