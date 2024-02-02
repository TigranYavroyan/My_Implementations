#include "DoublyLinkedList.hpp"
#include <iostream>
//---------------------------ctors and dtor------------------------------
Dlist::Dlist () = default;

Dlist::Dlist (const Dlist& other) {
    if (other.head == nullptr)
        return;
    Node *tmp = other.head;
    while (tmp != nullptr) {
        push_back(tmp->value);
        tmp = tmp->next;
    }
}

Dlist::Dlist (Dlist&& other) {
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
}

Dlist::~Dlist () {
    erase();
}
//------------------------member functions---------------------------------
bool Dlist::empty () const {
    if (head == nullptr)
        return true;
    return false;
}

void Dlist::push_back (int value) {
    if (head == nullptr) {
        head = new Node();
        head->value = value;
        tail = head;
        return;
    }

    Node *tmp = head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = new Node();
    tmp->next->value = value;
    tmp->next->prev = tmp;
    tail = tmp->next;
}

void Dlist::push_front (int value) {
    if (head == nullptr) {
        head = new Node();
        head->value = value;
        tail = head;
        return;
    }
    Node* tmp = head;
    head = new Node();
    head->value = value;
    head->next = tmp;
    tmp->prev = head;
}

void Dlist::display () const {
    if (head == nullptr) {
        std::cout << "There is no nodes" << std::endl;
        return;
    }
    Node *tmp = head;
    while (tmp) {
        std::cout << tmp->value << ' ';
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

void Dlist::erase () {
    while (head) {
        pop_front();
    }
}

void Dlist::pop_back () {
    if (tail == nullptr)
        return;
    if (tail == head) {
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node *tmp = tail->prev;
        tmp->next = nullptr;
        delete tail;
        tail = tmp;
    }
}

void Dlist::pop_front () {
    if (head == nullptr)
        return;
    if (tail == head) {
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node *tmp = head->next;
        tmp->prev = nullptr;
        delete head;
        head = tmp;
    }
}

void Dlist::remove (int data) {
    
}

void Dlist::insert (int index, int data) {

}

// int Dlist::size () const {

// }

// int Dlist::get (int index) const {

// }
// //------------------------------operators------------------------------
// Dlist& Dlist::operator= (const Dlist& rhs) {

// }

// const Dlist& Dlist::operator= (Dlist&& rhs) {

// }

// Dlist Dlist::operator+ (const Dlist& rhs) const {

// }

// int& Dlist::operator[] (int index) {
//     return const_cast<int&>(static_cast<const Dlist&>(*this)[index]);
// }

// const int& Dlist::operator[] (int index) const {

// }

// bool Dlist::operator== (const Dlist& rhs) const {

// }

//--------------------------------------------------------------------------------