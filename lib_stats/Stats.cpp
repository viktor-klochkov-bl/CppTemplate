#include "Stats.hpp"

#include <stdexcept>

namespace lib_stats {

double sum(std::vector<double> values) {
    double result = 0;
    for (int i = 0; i < values.size(); i++) {
        result = result + values[i];
    }
    return result;
}

double average(std::vector<double> values) {
    if (values.size() == 0) {
        throw std::invalid_argument("Cannot average empty vector");
    }
    double total = 0;
    for (int i = 0; i < values.size(); i++) {
        total = total + values[i];
    }
    return total / values.size();
}

double max(std::vector<double> values) {
    if (values.size() == 0) {
        throw std::invalid_argument("Cannot find max of empty vector");
    }
    double result = values[0];
    for (int i = 1; i < values.size(); i++) {
        if (values[i] > result) {
            result = values[i];
        }
    }
    return result;
}

double min(std::vector<double> values) {
    if (values.size() == 0) {
        throw std::invalid_argument("Cannot find min of empty vector");
    }
    double result = values[0];
    for (int i = 1; i < values.size(); i++) {
        if (values[i] < result) {
            result = values[i];
        }
    }
    return result;
}

std::vector<double> filter_greater_than(std::vector<double> values, double threshold) {
    std::vector<double> result;
    for (int i = 0; i < values.size(); i++) {
        if (values[i] > threshold) {
            result.push_back(values[i]);
        }
    }
    return result;
}

}
