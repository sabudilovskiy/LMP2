#include "gtest/gtest.h"
#include "classes/File.h"

TEST(FileTest, FilePath) {
    File file1("C:/adb", "adb", "exe",
               Date(12,10,2021),
               Size(1, 581, 2, 0));
    File file2("C:/adb", "adb", "",
               Date(12,10,2021),
               Size(1, 581, 2, 0));
    EXPECT_EQ(file1.getPath(), "C:/adb/adb.exe");
    EXPECT_EQ(file2.getPath(), "C:/adb/adb");
}
TEST(FileTest, FileError){
    EXPECT_THROW(File("C:/adb", "", "exe",
                       Date(12,10,2021),
                       Size(1, 581, 2, 0)), std::invalid_argument);
    EXPECT_THROW(File("", "adb", "exe",
                      Date(12,10,2021),
                      Size(1, 581, 2, 0)), std::invalid_argument);
    EXPECT_THROW(File("C:/adb", "", "exe",
                      Date(29,2,2021),
                      Size(1, 581, 2, 0)), std::invalid_argument);
    EXPECT_THROW(File("C:/adb", "", "exe",
                      Date(12,10,2021),
                      Size(1025, 581, 2, 1)), std::invalid_argument);
}

TEST(FileTest, FileFromString) {
    File file("C:/adb/adb.exe;12.10.2021;1 B");
    EXPECT_EQ(file.getPath(), "C:/adb/adb.exe");
    EXPECT_EQ(file.getDate().getDay(), 12);
    EXPECT_EQ(file.getDate().getMonth(), 10);
    EXPECT_EQ(file.getDate().getYear(), 2021);
    EXPECT_EQ(file.getSize().getByte(), 1);
    EXPECT_EQ(file.getSize().getKilobyte(), 0);
    EXPECT_EQ(file.getSize().getMegabyte(), 0);
    EXPECT_EQ(file.getSize().getGigabyte(), 0);
}
