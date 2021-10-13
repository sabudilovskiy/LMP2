#include "gtest/gtest.h"
#include "classes/Node.h"

TEST(NodeTest, NodeInt) {
    Node<int> check(5);
    EXPECT_EQ(check.getValue(), 5);
}
