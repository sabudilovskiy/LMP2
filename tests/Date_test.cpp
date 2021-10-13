#include "gtest/gtest.h"
#include "classes/Date.h"


TEST(DateTest, CreateDate) {
    Date date = Date(1,1,2020);
    EXPECT_EQ(date.toString(), "01.01.2020");
}
TEST(DateTest, ErrorDate){
    EXPECT_THROW(Date(0, 1, 1991), std::invalid_argument);
    EXPECT_THROW(Date(29, 2, 2021), std::invalid_argument);
}
TEST(DateTest, FromString){
    Date date1("12.10.2021"), date2("01.01.1999");
    EXPECT_EQ(date1.getDay(), 12);
    EXPECT_EQ(date1.getMonth(), 10);
    EXPECT_EQ(date1.getYear(), 2021);
    EXPECT_EQ(date2.getDay(), 1);
    EXPECT_EQ(date2.getMonth(), 1);
    EXPECT_EQ(date2.getYear(), 1999);
}

