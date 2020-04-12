/* Copyright (c) 2019 verthais */

#include <numeric>
#include <stdlib.h>
#include <limits>

#include "gtest/gtest.h"

static int solution(std::vector<int> &A) {
    if(A.size() == 2) return abs(A[0]-A[1]);

    long lhs{};
    long rhs = std::accumulate(A.begin(), A.end(), static_cast<long>(0));

    long rv = std::numeric_limits<long>::max();

    for(auto itr = A.begin(); itr!= A.end()-1; ++itr)
    {
        lhs += *itr;
        rhs -= *itr;
        auto tmp = abs(lhs-rhs);

        if(rv > tmp)
            rv = tmp;
    }

    return rv;
}

TEST(tape_equilibrium_test, simple)
{
    std::vector<int> nums {5, 6, 2, 4, 1};
    constexpr const int expected{4};

    EXPECT_EQ(expected, solution(nums));
}

TEST(tape_equilibrium_test, negativ)
{
    std::vector<int> nums {-2, -3, -4, -1};
    constexpr const int expected{0};

    EXPECT_EQ(expected, solution(nums));
}

TEST(tape_equilibrium_test, zero)
{
    std::vector<int> nums {-10, -20, -30, -40, 100};
    constexpr const int expected{0};

    EXPECT_EQ(expected, solution(nums));
}