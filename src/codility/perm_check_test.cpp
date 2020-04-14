/* Copyright (c) 2019 verthais */

#include <set>
#include <numeric>
#include <vector>

#include "gtest/gtest.h"

using ull = unsigned long long;

const int solution(const std::vector<int> &A) noexcept {
    std::set<int> a(A.begin(), A.end());
    if(a.size() != A.size())
        return 0;

    if(*--a.end() > static_cast<int>(a.size()))
        return 0;

    return 1;
}

TEST(perm_check_test, simple)
{
    std::vector<std::pair<int,std::vector<int>>> refs {
        { 1, {3, 1, 4, 2}},
        { 0, { 3, 1, 4, }}
    };

    for(const auto [expected, nums] : refs)
        EXPECT_EQ(expected, solution(nums));
}