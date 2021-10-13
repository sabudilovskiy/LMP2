//
// Created by asus on 12.10.2021.
//
#include "gtest/gtest.h"
#include "classes/Size.h"

TEST(SizeTest, SizeToString) {
    Size size1(1, 2, 3, 4),
    size2(0, 0, 0, 0),
    size3(0, 0, 1, 0);
    EXPECT_EQ(size1.to_string(), "4 GB, 3 MB, 2 KB, 1 B");
    EXPECT_EQ(size2.to_string(), "0 B");
    EXPECT_EQ(size3.to_string(), "1 MB");

}

TEST(SizeTest, SizeError) {
    EXPECT_THROW(Size(1,1025, 2, 2), std::invalid_argument);
    EXPECT_THROW(Size(-1,1, 2, 2), std::invalid_argument);
}

TEST(SizeTest, SizeFromString) {
    Size size1 = Size("4 GB, 3 MB, 2 KB, 1 B");
    Size size2 = Size("3 MB, 2 KB, 1 B");
    Size size3 = Size("1 MB");
    EXPECT_EQ(size1.getGigabyte(), 4);
    EXPECT_EQ(size1.getMegabyte(), 3);
    EXPECT_EQ(size1.getKilobyte(), 2);
    EXPECT_EQ(size1.getByte(), 1);
    EXPECT_EQ(size2.getGigabyte(), 0);
    EXPECT_EQ(size2.getMegabyte(), 3);
    EXPECT_EQ(size2.getKilobyte(), 2);
    EXPECT_EQ(size2.getByte(), 1);
    EXPECT_EQ(size3.getGigabyte(), 0);
    EXPECT_EQ(size3.getMegabyte(), 1);
    EXPECT_EQ(size3.getKilobyte(), 0);
    EXPECT_EQ(size3.getByte(), 0);
}

TEST(SizeTest, SizeErrorFromString) {
    EXPECT_THROW(Size("чё тут?"), std::invalid_argument);
    EXPECT_THROW(Size(""), std::invalid_argument);
    EXPECT_THROW(Size("2B"), std::invalid_argument);
    EXPECT_THROW(Size("1 MB, 1 MB"), std::invalid_argument);
    EXPECT_THROW(Size("1 MB , 1 KB"), std::invalid_argument);
}
