//
// Created by asus on 04.10.2021.
//
#include <string>
#ifndef LMP2_DATE_H
#define LMP2_DATE_H


class Date {
    int day = -1, month = -1, year = -1;
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
public:
    Date();
    Date(const std::string&);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    Date(int day, int month, int year);
    std::string toString() const;
};


#endif //LMP2_DATE_H
