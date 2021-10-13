#include <iostream>
#include <fstream>
#include "classes/File.h"
#include "classes/LinkedList.h"
#include <Windows.h>
#define TEST_MODE
#ifndef TEST_MODE
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string in, out;
    std::cout << "Введите путь к файлу с данными о файлах: ";
    std::cin >> in;
    std::ifstream file_in(in);
    auto func = [](File left, File right){ return left.getCatalog() > right.getCatalog();};
    if (file_in.is_open()){
        LinkedList<File> list;
        std::string buffer;
        bool error = false;
        while (!file_in.eof() && !error){
            std::getline(file_in, buffer);
            try{
                list.pushBackPrevComparator(File(buffer), func);
            }
            catch (std::invalid_argument){
                error = true;
            }
        }
        std::cout << "Чтение произошло успешно. \nВведите путь к файлу для записи: ";
        std::cin >> out;
        std::ofstream file_out(out);
        if (file_out.is_open()){
            std::string cur_catalog;
            int i = 0;
            while (i < list.getSize()){
                if (list.getCurrent().getExtension() == "cpp" || list.getCurrent().getExtension() == "exe"){
                    if (list.getCurrent().getCatalog() == list.getCurrent().getNameFile()){
                        if (cur_catalog == list.getCurrent().getCatalog()) {
                            file_out << list.getCurrent().getPath() << '\n';
                        }
                        else {
                            cur_catalog = list.getCurrent().getCatalog();
                            file_out << cur_catalog << '\n';
                            file_out << list.getCurrent().getPath() << '\n';
                        }
                    }
                }
                list.moveRight();
            }
            file_out.close();
            std::cout << "Запись произведена успешно.";
            std::cin.get();
            std::cin.get();
        }
        else {
            std::cout << "Нет доступа к файлу для записи.";
        }

    }
    else {
        std::cout << "Нет доступа к файлу.";
    }
}
#endif