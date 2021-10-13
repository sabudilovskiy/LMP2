//
// Created by asus on 04.10.2021.
//

#ifndef LMP2_SIZE_H
#define LMP2_SIZE_H


#include <string>

class Size {
    int byte, kilobyte, megabyte, gigabyte;
public:
    Size(int byte, int kilobyte, int megabyte, int gigabyte);
    Size(const std::string&);
    int getByte() const;
    int getKilobyte() const;
    int getMegabyte() const;
    int getGigabyte() const;
    std::string to_string();
};


#endif //LMP2_SIZE_H
