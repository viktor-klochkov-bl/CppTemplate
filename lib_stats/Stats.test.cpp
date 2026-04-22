#include "Stats.hpp"

#include "gtest/gtest.h"

namespace lib_stats {

TEST(Stats, sum_basic) {
    EXPECT_EQ(sum({1.0, 2.0, 3.0}), 6.0);
}

TEST(Stats, sum_empty) {
    EXPECT_EQ(sum({}), 0.0);
}

TEST(Stats, average_basic) {
    EXPECT_EQ(average({1.0, 2.0, 3.0}), 2.0);
}

TEST(Stats, average_empty_throws) {
    EXPECT_THROW(average({}), std::invalid_argument);
}

TEST(Stats, max_basic) {
    EXPECT_EQ(max({3.0, 1.0, 2.0}), 3.0);
}

TEST(Stats, max_empty_throws) {
    EXPECT_THROW(max({}), std::invalid_argument);
}

TEST(Stats, min_basic) {
    EXPECT_EQ(min({3.0, 1.0, 2.0}), 1.0);
}

TEST(Stats, min_empty_throws) {
    EXPECT_THROW(min({}), std::invalid_argument);
}

TEST(Stats, filter_greater_than_basic) {
    std::vector<double> result = filter_greater_than({1.0, 5.0, 3.0, 8.0}, 4.0);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], 5.0);
    EXPECT_EQ(result[1], 8.0);
}

TEST(Stats, filter_greater_than_none_match) {
    std::vector<double> result = filter_greater_than({1.0, 2.0}, 10.0);
    EXPECT_EQ(result.size(), 0);
}

}
