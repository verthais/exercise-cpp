// Copyright (c) 2020 verthais

#include "gtest/gtest.h"

#include <numeric>
#include <vector>

static int solution(std::vector<int> &A) {
    if(A.empty()) return 1;
    if(A.size() == 1) return 3 - A[0];

    double value = static_cast<double>(2 + A.size()) / 2 * (A.size()+1);
    double sum = std::accumulate(std::begin(A), std::end(A), static_cast<double>(0));

    return static_cast<int>(value-sum);
}

TEST(perm_missing_elem_test, simple)
{
    std::vector<int>nums{1,2,3,4,5};
    EXPECT_EQ(6, solution(nums));
}

TEST(perm_missing_elem_test, empty)
{
    std::vector<int> nums{};
    EXPECT_EQ(1, solution(nums));
}

TEST(perm_missing_elem_test, single)
{
    std::vector<int>nums{1};
    EXPECT_EQ(2, solution(nums));

    nums.pop_back();
    nums.push_back(2);

    EXPECT_EQ(1, solution(nums));
}