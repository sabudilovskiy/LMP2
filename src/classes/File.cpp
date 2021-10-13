//
// Created by asus on 04.10.2021.
//

#include <stdexcept>
#include "File.h"

File::File(const std::string& input) {
    int i(0);
    std::string buf;
    while (i < input.length() && input[i] != ';') buf+=input[i++];
    if (i == input.length()) throw std::invalid_argument("");
    int point(-1), slash(-1);
    int j(buf.length() - 1);
    while (j > -1 && (point == -1 || slash == -1)){
        if (point ==-1 && buf[j] == '.') {
            point = j;
        }
        else if (slash == -1 && buf[j] == '/' ) {
            slash = j;
        }
        j--;
    }
    if (point != -1){
        if (point < slash) throw std::invalid_argument("");
        else {
            catalog = buf.substr(0, slash);
            nameFile = buf.substr(slash + 1, point - slash - 1);
            extension = buf.substr(point + 1);
        }
    }
    else if(slash != -1){
        catalog = buf.substr(0, slash);
        nameFile = buf.substr(slash + 1);
    }
    else throw std::invalid_argument("");
    buf = "";
    i++;
    while (i < input.length() && input[i] != ';')
    {
        buf+=input[i++];
    }
    if (i == input.length()) throw std::invalid_argument("");
    date = Date(buf);
    buf = input.substr(i+1);
    size = Size(buf);
}

File::File(const std::string &catalog,
           const std::string &nameFile,
           const std::string &extension,
           const Date &date,
           const Size &size) : extension(extension), date(date), size(size) {
    if (!catalog.empty()) this->catalog = catalog;
    else throw std::invalid_argument("");
    if (!nameFile.empty()) this->nameFile = nameFile;
    else throw std::invalid_argument("");
}
std::string File::getPath() {
    std::string buf;
    buf += catalog + "/" + nameFile;
    if (extension != "") buf += "." + extension;
    return buf;
}
const std::string& File::getCatalog() const {
    return catalog;
}

const std::string& File::getNameFile() const {
    return nameFile;
}

const std::string& File::getExtension() const {
    return extension;
}

const Date& File::getDate() const {
    return date;
}

const Size& File::getSize() const {
    return size;
}

File::File() {
}






