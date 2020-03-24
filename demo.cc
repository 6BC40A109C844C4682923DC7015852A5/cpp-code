#include "SqList.h"
#include "LinkList.h"
#include "SeqStack.h"
#include "BrMatch.h"
#include "gtest/gtest.h"

// test for sequential list
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

// test for linked list
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

TEST(Suite2, test_in_rm){
    LinkList<int> llist;
    const int N = 5;
    for (int i = 0; i < N; ++i)
        llist.insert(i + 1);

    EXPECT_EQ(llist.insert(6, 8), false);
    EXPECT_EQ(llist.remove(1), 2);
}

TEST(Suite2, test_empty_get_set){
    LinkList<int> llist;
    llist.insert(4);
    llist.insert(5);

    llist.set(0, 3);
    llist.set(1, 5);
    EXPECT_EQ(llist.get(0), 3);

    llist.remove(0);
    llist.remove(0);
    EXPECT_EQ(llist.isEmpty(), true);
}

TEST(Suite2, test_rmall_con){
    LinkList<int> llist;
    const int N = 4;

    for (int i = 0; i < N; ++i)
        llist.insert(5);

    EXPECT_EQ(llist.contains(5), N);
    EXPECT_EQ(llist.removeAll(5), N);
}


// test for sequential stack
TEST(Suite3, test_push_pop){
    SqStack<int> sta(4);
    const int N = 4;
    for (int i = 0; i < N; ++i)
        sta.push(i + 1);

    EXPECT_EQ(sta.push(5), false);
    EXPECT_EQ(sta.pop(), 4);
}

// test for bracket matching
TEST(Suite4, test_brMatch){
    std::string const br1("{[(a * b) + c] / d} + 1");
    std::string const br2("{(a * b) - c] + d} - 1");

    EXPECT_EQ(brMatch(br1), true);
    EXPECT_EQ(brMatch(br2), false);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
