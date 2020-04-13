/* Copyright (c) 2020 verthais */

#include "gtest/gtest.h"

#include <algorithm>
#include <array>
#include <utility>
#include <vector>

static int solution(int X, std::vector<int>& A)
{
    std::array<bool, 100'001> bitmap { false };

    for (size_t i {}; i < A.size(); ++i) {
        if (!bitmap[A[i]]) {
            bitmap[A[i]] = true;
            --X;
            if (X == 0)
                return i;
        }
    }

    return -1;
}

TEST(frog_river_one_test, simple)
{
    std::vector<std::tuple<int, int, std::vector<int>>> refs = {
        std::make_tuple<int, int, std::vector<int>>(6, 5, { 1, 3, 1, 4, 2, 3, 5, 4 }),
        std::make_tuple<int, int, std::vector<int>>(-1, 2, { 1, 1, 1, 1 }),
        std::make_tuple<int, int, std::vector<int>>(-1, 5, { 3 })
    };

    for (auto [expected, X, A] : refs)
        EXPECT_EQ(expected, solution(X, A));
}
