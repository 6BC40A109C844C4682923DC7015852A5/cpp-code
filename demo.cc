#include "SqList.h"
#include "LinkList.h"
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
    EXPECT_EQ(sq.remove(6), 7);
    EXPECT_EQ(sq.insert(7, 8), false);
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

TEST(Suite1, test_empty_get_set){
    Sqlist<int> sq(2);
    const int N = 2;

    sq.insert(4);
    sq.insert(5);

    sq.set(0, 3);
    sq.set(1, 5);
    EXPECT_EQ(sq.get(0), 3);

    sq.remove(0);
    sq.remove(1);
    EXPECT_EQ(sq.isEmpty(), true);
}

TEST(Suite1, test_rmall_con){
    Sqlist<int> sq(4);
    const int N = 4;

    for (int i = 0; i < N; ++i)
        sq.insert(5);

    EXPECT_EQ(sq.contains(5), N);
    EXPECT_EQ(sq.removeAll(5), N);
}

TEST(Suite2, test_in_trav){
    LinkList<int> llist;
    const int N = 5;
    for (int i = 0; i < N; ++i)
        llist.insert(i + 1);

    int n = 1;
    for(int d : llist){
        EXPECT_EQ(d, n);
        n++;
    }

    EXPECT_EQ(n ,N + 1);

    static int s = 0;
    llist.traversal([](int d){ s += d; });
    EXPECT_EQ(s, 15);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
