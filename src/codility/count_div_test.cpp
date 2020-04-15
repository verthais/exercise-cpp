/* Copyright (c) 2020 verthais */

#include <cmath>
#include <vector>
#include "gtest/gtest.h"

static constexpr int solution(const int A,const int B,const int K) noexcept {
    int inclusive = ((A%K)==0) ? 1 : 0;
    if (!inclusive)
    {
        return std::round(
            static_cast<double>(B)/K
            - static_cast<double>(A)/K
            + inclusive
        );
    }
    return static_cast<double>(B)/K
        - static_cast<double>(A)/K
        + inclusive;
}

TEST(count_div_test, simple)
{
    const std::vector<std::tuple<int,int,int,int>> refs = {
        {2, 11, 14, 2},
        {2, 0, 2, 2},
        // {12345, 101, 123456789, 10000}
    };

    for(const auto& [expected, A, B, K] : refs)
    {
        EXPECT_EQ(expected, solution(A,B,K));
    }
}