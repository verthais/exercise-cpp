/* Copyright (c) 2019 verthais */

#include <limits>

#include "gtest/gtest.h"

int solution(int N)
{
    unsigned long int max = std::numeric_limits<unsigned long int>::min();
    unsigned long int temp {};
    bool opening_one { false };

    while (N) {
        if (N & 1) {
            if (!opening_one) {
                opening_one = true;
            } else {
                if (max < temp) {
                    max = temp;
                }
                temp = 0;
            }
        } else {
            if (opening_one)
                ++temp;
        }
        N = N >> 1;
    }

    return max;
}

TEST(binary_gap_test, simple)
{
    EXPECT_EQ(2, solution(9));
    EXPECT_EQ(0, solution(32));
    EXPECT_EQ(0, solution(14));
    EXPECT_EQ(0, solution(15));
    EXPECT_EQ(4, solution(74901729));
}