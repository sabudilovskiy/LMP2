//
// Created by asus on 04.10.2021.
//

#include "Date.h"
#include <stdexcept>
#include <string>

Date::Date(int day, int month, int year) {
    setYear(year);
    setMonth(month);
    setDay(day);
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::setDay(int day) {
    if (1<=day && day <= 28){
        Date::day = day;
    }
    else if (day == 29){
        if (month != 2) Date::day = day;
        else if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0){
            Date::day = day;
        }
        else throw std::invalid_argument("");
    }
    else if (day == 30){
        if (month != 2)  Date::day = day;
        else throw std::invalid_argument("");
    }
    else if (day == 31){
        if (month <= 7 && month % 2 == 1 || month > 7 && month % 2 == 0){
            Date::day = day;
        }
        else throw std::invalid_argument("");
    }
    else throw std::invalid_argument("");

}

void Date::setMonth(int month) {
    if (1<= month && month <= 12) Date::month = month;
    else throw std::invalid_argument("");
}

void Date::setYear(int year) {
    if (year > 0) {
        Date::year = year;
    }
    else throw std::invalid_argument("");
}

std::string Date::toString() const {
    std::string buffer;
    if (day < 10) buffer+='0';
    buffer+=std::to_string(day) + '.';
    if (month < 10) buffer+= '0';
    buffer+=std::to_string(month) + '.';
    buffer+=std::to_string(year);
    return buffer;
}

Date::Date() {}

Date::Date(const std::string& input) {
    if (input.length() != 10) throw std::invalid_argument("");
    if (input[2] != '.' || input[5] != '.') throw std::invalid_argument("");
    setDay(std::stoi(input.substr(0,2)));
    setMonth(std::stoi(input.substr(3,2)));
    setYear(std::stoi(input.substr(6,4)));
}
