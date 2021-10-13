//
// Created by asus on 04.10.2021.
//
#include <string>
#ifndef LMP2_NODE_H
#define LMP2_NODE_H
template <class T>
class Node {
   T value;
   Node<T>* next = nullptr;
   Node<T>* prev = nullptr;
public:
    Node();
    Node(T t);
    T getValue() const;
    void setValue(T value);
    Node<T> *getNext() const;
    void setNext(Node<T> *next);
    Node<T> *getPrev() const;
    void setPrev(Node<T> *prev);
};
#endif //LMP2_NODE_H
