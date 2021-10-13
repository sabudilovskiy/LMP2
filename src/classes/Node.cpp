//
// Created by asus on 04.10.2021.
//

#include "Node.h"
template<class T>
Node<T>::Node() {
}
template<class T>
Node<T>::Node(T t) {
    value = t;
}
template<class T>
T Node<T>::getValue() const {
    return value;
}
template<class T>
void Node<T>::setValue(T value) {
    Node::value = value;
}
template<class T>
Node<T> *Node<T>::getNext() const {
    return next;
}
template<class T>
void Node<T>::setNext(Node<T> *next) {
    Node::next = next;
}
template<class T>
Node<T> *Node<T>::getPrev() const {
    return prev;
}
template<class T>
void Node<T>::setPrev(Node<T> *prev) {
    Node::prev = prev;
}
