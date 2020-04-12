/* Copyright (c) 2019 verthais */

#include <algorithm>
#include <unordered_map>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

static int solution(std::vector<int>& in) noexcept
{
    std::unordered_map<int, int> index;
    for (auto e : in) {
        if (index.find(e) != index.end()) {
            if (index[e])
                index[e] = 0;
            else
                ++index[e];
        } else {
            index[e] = 1;
        }
    }

    for (const auto& e : index) {
        if (e.second == 1)
            return e.first;
    }

    return in.front();
}

TEST(odd_occurrences, simple)
{
    std::vector<int> in { 9, 3, 9, 3, 9, 7, 1, 1, 3, 9,
        3, 9, 7, 9, 9, 3, 6, 3, 9, 7 };
    EXPECT_EQ(solution(in), 6);
}