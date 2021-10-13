//
// Created by asus on 04.10.2021.
//
#include <string>
#include "Date.h"
#include "Size.h"

#ifndef LMP2_FILE_H
#define LMP2_FILE_H


class File {
    std::string catalog, nameFile, extension;
    Date date =  Date(1,1, 1970);
    Size size = Size(0,0,0,0);
public:
    File();
    File(const std::string &catalog,
         const std::string &nameFile,
         const std::string &extension,
         const Date &date,
         const Size &size);
    File(const std::string& input);
    std::string getPath();
    const std::string& getCatalog() const;
    const std::string& getNameFile() const;
    const std::string& getExtension() const;
    const Date& getDate() const;
    const Size& getSize() const;
};


#endif //LMP2_FILE_H
