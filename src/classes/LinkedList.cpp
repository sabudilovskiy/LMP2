
#include "LinkedList.h"
#include <stdexcept>
template<class T>
int LinkedList<T>::getSize() const {
    return size;
}

template<class T>
void LinkedList<T>::push_back(T t) {
    size++;
    if (last!= nullptr) {
        last->setNext(new Node(t));
        last->getNext()->setPrev(last);
        last = last->getNext();
    }
    else {
        last = new Node(t);
        first = last;
        cur = first;
    }
}

template<class T>
void LinkedList<T>::clear() {
    cur = first;
    while (cur != nullptr) {
        Node<T>* temp = cur->getNext();
        delete cur;
        cur = temp;
    }
    size = 0;
    cur = nullptr;
    first = nullptr;
    last = nullptr;
}

template<class T>
void LinkedList<T>::loseControl() {
    size = 0;
    cur = nullptr;
    first = nullptr;
    last = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<class T>
std::string LinkedList<T>::to_string(std::string (*toString)(T)) {
    if (size > 0){
    std::string buffer;
    Node<T>* cur_node = first;
    for (int i = 0; i < size; i++) buffer += toString(cur_node->getValue()) + ", ";
    buffer.resize(buffer.length() - 2);
    return buffer;}
    else return "";
}


template<class T>
void LinkedList<T>::moveRight() {
    if (cur!= nullptr && cur->getNext() != nullptr) cur = cur->getNext();
    else throw std::out_of_range("");
}

template<class T>
void LinkedList<T>::moveLeft() {
    if (cur!= nullptr && cur->getPrev() != nullptr) cur = cur->getPrev();
    else throw std::out_of_range("");
}

template<class T>
T LinkedList<T>::getCurrent() {
    return cur->getValue();
}
template<class T>
void LinkedList<T>::setCurrent(T t) {
    cur->setValue(t);
}

template<class T>
void LinkedList<T>::pushBackPrevComparator(T t, bool (*comparator)(T, T)) {
    if (size > 0){
        Node<T>* cur_node = first;
        while (cur_node != nullptr && !comparator(t, cur_node->getValue())) cur_node = cur_node->getNext();
        if (cur_node != nullptr){
            if (cur_node->getPrev()!= nullptr) {
                Node<T>* temp_node = new Node(t);
                cur_node->getPrev()->setNext(temp_node);
                temp_node->setPrev(cur_node->getPrev());
                temp_node->setNext(cur_node);
                cur_node->setPrev(cur_node);
                size++;
            }
            else add_begin(t);
        }
        else push_back(t);
    }
    else push_back(t);
}

template<class T>
void LinkedList<T>::add_begin(T t) {
    size++;
    if (first != nullptr){
        first->setPrev(new Node(t));
        first->getPrev()->setNext(first);
        first=first->getPrev();
    }
    else {
        first = new Node(t);
        last = first;
        cur = first;
    }
}
