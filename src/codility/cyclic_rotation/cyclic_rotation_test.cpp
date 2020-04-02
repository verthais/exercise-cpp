#include <algorithm>
#include <iostream>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

std::vector<int>
solution(std::vector<int>& A, int K)
{
    if (A.size() == 0)
        return A;
    else if (K == A.size())
        return A;
    else if (K > A.size())
        while (K > A.size())
            K -= A.size();
    auto newBegin = A.end() - K;
    std::rotate(A.begin(), newBegin, A.end());
    return A;
}

TEST(cyclic_rotation, simple)
{
    std::vector<int> A {};
    std::vector<int> B { 3, 8, 9, 7, 6 };
    EXPECT_THAT(solution(A, 3), ::testing::IsEmpty());
    EXPECT_THAT(solution(B, 3), ::testing::ElementsAreArray({ 9, 7, 6, 3, 8 }));
}