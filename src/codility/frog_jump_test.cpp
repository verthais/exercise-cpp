// Copyright (c) 2020 verthais

#include "gtest/gtest.h"
#include <iostream>

static int solution(int X, int Y, int D)
{
    Y -= X;

    if (Y % D) {
        return Y / D + 1;
    } else {
        return Y / D;
    }
}

TEST(frog_jump_test, simple)
{
    EXPECT_EQ(3, solution(10, 85, 30));
}