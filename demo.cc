#include "SqList.h"
#include "gtest/gtest.h"

TEST(Suite1, test_in_rm){
    Sqlist<int> sq(7);
    const int N = 7;

    for (int i = 0; i < N; ++i)
        sq.insert(i + 1);

    int n = 1;

    for(int d : sq){
        EXPECT_EQ(d, n);
        n++;
    }

    EXPECT_EQ(n ,8);

    EXPECT_EQ(sq.insert(1), false);
}

TEST(Suite1, test_trav){
    Sqlist<int> sq(7);
    const int N = 7;

    for (int i = 0; i < N; ++i) {
        sq.insert(i + 1);
    }

    static int s = 0;
    sq.traversal([](int d){ s += d; });
    EXPECT_EQ(s, 28);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
