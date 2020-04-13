

#include <algorithm>

#include "gtest/gtest.h"

std::vector<int> solution(int N, std::vector<int>& A)
{
    std::vector<int> v(N,0);
    int max {};
    int current {};

    for (const auto& e : A) {
        if (e == N + 1) {
            current = max;
        } else {
            int idx { e - 1 };
            if (v[idx] < current)
                v[idx] = current;

            ++v[idx];

            if (v[idx] > max)
                max = v[idx];
        }
    }

    for (auto& e : v)
        if (e < current)
            e = current;

    return v;
}

TEST(max_counters_test, simple)
{
    std::vector<int> nums { 3, 4, 4, 6, 1, 4, 4 };
    std::vector<int> expected { 3, 2, 2, 4, 2 };

    EXPECT_EQ(expected, solution(5, nums));
}
