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

    Node *tmp = tail;
    tmp->next = new Node();
    tmp->next->value = value;
    tmp->next->prev = tmp;
    tail = tmp->next;
}
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
    if (head == nullptr)
        return;
    if (head->value == data)
        pop_front();
    else if (tail->value == data)
        pop_back();
    else {    
        Node *tmp = head;
        while (tmp) {
            if (data == tmp->value)
            {
                tmp->next->prev = tmp->prev;
                tmp->prev->next = tmp->next;
                delete tmp;
                return;
            }
            tmp = tmp->next;
        }
    }
}

void Dlist::insert (unsigned int index, int data) {
    unsigned int size = this->size();
    if (index > size)
        throw std::invalid_argument("Invalid index");
    if (index == 0 || head == nullptr)
        push_front(data);
    else if (index == size)
        push_back(data);
    else {
        Node *tmp = head;
        unsigned int count = 0;
        while (tmp) {
            if (count == index)
            {
                Node *prev = tmp->prev;
                prev->next = new Node();
                prev->next->value = data;
                tmp->prev = prev->next;
                prev->next->prev = prev;
                prev->next->next = tmp;
                return;
            }
            tmp = tmp->next;
            ++count;
        }
    }
}

unsigned int Dlist::size () const {
    Node* tmp = head;
    int count = 0;
    while (tmp) {
        tmp = tmp->next;
        ++count;
    }
    return count;
}

int Dlist::get (unsigned int index) const {
    if (index >= this->size())
        throw std::invalid_argument("Invalid index");
    int count = 0;
    Node *tmp = head;
    while (tmp) {
        if (count == index)
            return tmp->value;
        tmp = tmp->next;
        ++count;
    }
    return 0;
}
// //------------------------------operators------------------------------
Dlist& Dlist::operator= (const Dlist& rhs) {
    if (this == &rhs)
        return *this;
    if (rhs.head == nullptr)
        erase();
    else {
        Node *tmp = rhs.head;
        while (tmp != nullptr) {
            push_back(tmp->value);
            tmp = tmp->next;
        }
    }
    return *this;
}

const Dlist& Dlist::operator= (Dlist&& rhs) {
    head = rhs.head;
    tail = rhs.tail;
    rhs.head = nullptr;
    rhs.tail = nullptr;
    return *this;
}

Dlist Dlist::operator+ (const Dlist& rhs) const {
    Dlist list = *this;
    Node *tmp = rhs.head;
    while (tmp) {
        list.push_back(tmp->value);
        tmp = tmp->next;
    }
    return list;
}

int& Dlist::operator[] (int index) {
    return const_cast<int&>(static_cast<const Dlist&>(*this)[index]);
}

const int& Dlist::operator[] (int index) const {
    int count = 0;

    Node* tmp = head;
    while (tmp != nullptr) {
        if (index == count)
            return tmp->value;
        tmp = tmp->next;
        ++count;
    }
    throw std::invalid_argument("Invalid index");
}

bool Dlist::operator== (const Dlist& rhs) const {
    if (rhs.size() != this->size())
        return false;
    Node *tmp_rhs = rhs.head;
    Node *tmp_lhs = this->head;
    while (tmp_lhs) {
        if (tmp_lhs->value != tmp_rhs->value)
            return false;
        tmp_rhs = tmp_rhs->next;
        tmp_lhs = tmp_lhs->next;
    }
    return true;
}
//--------------------------------------------------------------------------------
