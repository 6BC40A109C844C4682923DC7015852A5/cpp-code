#include "Btree.h"
#include "gtest/gtest.h"

TEST(Suite1, test){
    Btree<int> bt;
    LinkList<int> prl;
    LinkList<int> inl;
    LinkList<int> pol;
    int pre[] = {11, 22, 44, 77, 55, 88};
    int in[] = {44, 77, 22, 11, 55 ,88};
    int pos[] = {77, 44, 22, 88, 55, 11};

    bt.PreInCreate(pre, in, 5, 5);

    bt.PreOrder(prl);
    int i1 = 0;
    for(int d : prl){
        EXPECT_EQ(d, pre[i1]);
        i1++;
    }
    EXPECT_EQ(i1, 6);

    bt.InOrder(inl);
    int i2 = 0;
    for(int d : inl){
        EXPECT_EQ(d, in[i2]);
        i2++;
    }
    EXPECT_EQ(i2, 6);

    bt.PostOrder(pol);
    int i3 = 0;
    for(int d : pol){
        EXPECT_EQ(d, pos[i3]);
        i3++;
    }
    EXPECT_EQ(i3, 6);

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
