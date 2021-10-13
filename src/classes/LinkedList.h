//
// Created by asus on 04.10.2021.
//
#include "Node.h"
#ifndef LMP2_LINKEDLIST_H
#define LMP2_LINKEDLIST_H

template<class T>
class LinkedList {
    int size = 0;
    Node<T> *first = nullptr;
    Node<T> *last = nullptr;
    Node<T> *cur = nullptr;
public:
    void moveRight();
    void moveLeft();
    T getCurrent();
    void setCurrent(T t);
    void pushBackPrevComparator(T t, bool (*comparator)(T, T));
    void clear();
    int getSize() const;
    void push_back(T t);
    void add_begin(T t);
    ~LinkedList();
    std::string to_string(std::string (*)(T));
private:
    void loseControl();
};
#endif //LMP2_LINKEDLIST_H
