//
// Created by asus on 04.10.2021.
//

#include "Size.h"
#include <stdexcept>
Size::Size(int byte, int kilobyte, int megabyte, int gigabyte) {
    if (byte < 0 || byte > 1024) throw std::invalid_argument("");
    else this->byte = byte;
    if (kilobyte < 0 || kilobyte > 1024) throw std::invalid_argument("");
    else this->kilobyte = kilobyte;
    if (megabyte < 0 || megabyte > 1024) throw std::invalid_argument("");
    else this->megabyte = megabyte;
    if (gigabyte >= 0) this->gigabyte = gigabyte;
    else throw std::invalid_argument("");
}

Size::Size(const std::string& input) : byte(-1), kilobyte(-1), megabyte(-1), gigabyte(-1){
    int temp;
    int i = 0;
    if (input.length() == 0) throw std::invalid_argument("");
    while (i < input.length()){
        std::string buf;
        if (i!=0 && input[i] == ',') i+=2;
        while (i < input.length() && '0' <= input[i] && input[i] <= '9') buf+=input[i++];
        temp = std::stoi (buf);
        if (i == input.length()) throw std::invalid_argument("");
        if (input[i] == ' ') i++;
        else throw std::invalid_argument("");
        buf = "";
        while (i < input.size() && input[i] != ',') buf.push_back(input[i++]);
        if (buf == "GB" && gigabyte == -1) gigabyte = temp;
        else if (buf == "MB" && megabyte == -1) megabyte = temp;
        else if (buf == "KB" && kilobyte == -1) kilobyte = temp;
        else if (buf == "B" && byte == -1) byte = temp;
        else throw std::invalid_argument("");
    }
    if (byte == -1) byte = 0;
    if (kilobyte ==-1) kilobyte = 0;
    if (megabyte == -1) megabyte = 0;
    if (gigabyte == -1 ) gigabyte = 0;
}

int Size::getByte() const {
    return byte;
}

int Size::getKilobyte() const {
    return kilobyte;
}

int Size::getMegabyte() const {
    return megabyte;
}

int Size::getGigabyte() const {
    return gigabyte;
}

std::string Size::to_string() {
    std::string buffer;
    if (gigabyte > 0) buffer+= std::to_string(gigabyte) + " GB, ";
    if (megabyte > 0) buffer+= std::to_string(megabyte) + " MB, ";
    if (kilobyte > 0) buffer+= std::to_string(kilobyte) + " KB, ";
    if (byte > 0) buffer += std::to_string(byte) + " B";
    if (buffer.length() > 2 && buffer[buffer.length() - 2] == ',')
    {
        buffer.resize(buffer.length() - 2);
    }
    if (buffer != "") return buffer;
    else return "0 B";
}


