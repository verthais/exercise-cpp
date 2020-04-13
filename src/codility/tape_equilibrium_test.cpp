/* Copyright (c) 2019 verthais */

#include <limits>
#include <numeric>
#include <stdlib.h>

#include "gtest/gtest.h"

static int solution(const std::vector<int>& A)
{
    if (A.size() == 2)
        return abs(A[0] - A[1]);

    long lhs {};
    long rhs = std::accumulate(A.begin(), A.end(), static_cast<long>(0));

    long rv = std::numeric_limits<long>::max();

    for (auto itr = A.begin(); itr != A.end() - 1; ++itr) {
        lhs += *itr;
        rhs -= *itr;
        auto tmp = abs(lhs - rhs);

        if (rv > tmp)
            rv = tmp;
    }

    return rv;
}

TEST(tape_equilibrium_test, simple)
{
    std::vector<std::tuple<int, std::vector<int>>> refs = {
        std::make_tuple<int, std::vector<int>>(4, { 5, 6, 2, 4, 1 }),
        std::make_tuple<int, std::vector<int>>(0, { -2, -3, -4, -1 })
    };

    for (const auto& [expected, nums] : refs)
        EXPECT_EQ(expected, solution(nums));
}
