#include "linkedlist.hpp"
#include <iostream>

LinkedList::LinkedList () : head{nullptr} {}

LinkedList::LinkedList (const LinkedList& other) {
    Node* tmp = other.head;
    while (tmp != nullptr) {
        push_back(tmp->value);
        tmp = tmp->next;
    }
}

LinkedList::LinkedList (LinkedList&& rvalue) {
    head = rvalue.head;
    rvalue.head = nullptr;
}

LinkedList::~LinkedList () {
    erase();
}

bool LinkedList::empty () const {
    if (head == nullptr)
        return true;
    return false;
}
void LinkedList::push_back (int n) {
    if (head == nullptr) {
        head = new Node();
        head->value = n;
    }
    else {
        Node* tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new Node();
        tmp->next->value = n;
    }
}

void LinkedList::push_front (int n) {
    if (head == nullptr) {
        head = new Node();
        head->value = n;
    }
    else {
        Node* tmp = head;
        head = new Node();
        head->value = n;
        head->next = tmp;
    }
}
void LinkedList::display () const {
    if (head == nullptr) {
        std::cout << "There is no nodes" << std::endl;
        return;
    }
    Node* tmp = head;
    while (tmp != nullptr) {
        std::cout << tmp->value << ' ';
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

void LinkedList::erase () {
    while (head != nullptr)
        pop_front();
}

void LinkedList::pop_front () {
    if (head != nullptr) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
}

void LinkedList::pop_back () {
    if (head != nullptr) {
        Node* tmp = head;
        while (tmp->next->next != nullptr) {
            tmp = tmp->next;
        }
        delete tmp->next;
        tmp->next = nullptr;
    }
}

void LinkedList::insert (int index, int data) {
    if (index >= this->size())
        throw std::invalid_argument("Invalid index");
    if (index == 0)
        push_front(data);
    else if (index == (this->size() - 1))
        push_back(data);
    else {
        Node* tmp = head;
        for (int i = 0; i != (index - 1); ++i) {
            tmp = tmp->next;
        }
        Node* contin = tmp->next;
        tmp->next = new Node();
        tmp->next->value = data;
        tmp->next->next = contin;
    }
}

void LinkedList::remove (int data) {
    if (head->value == data) {
        pop_front();
        return;
    }
    for (Node* tmp = head; tmp->next != nullptr; tmp = tmp->next) {
        if (tmp->next->value == data) {
            Node* contin = tmp->next->next;
            delete tmp->next;
            tmp->next = contin;
            return;
        }
    }
    std::cout << "Nothing to remove" << std::endl;
}

int LinkedList::get (int index) const {
    return (*this)[index];
}

int LinkedList::size () const {
    int count = 0;

    Node* tmp = head;
    while (tmp != nullptr) {
        ++count;
        tmp = tmp->next;
    }

    return count;
}

int& LinkedList::operator[] (int index) {
    return const_cast<int&>(static_cast<const LinkedList&>(*this)[index]);
}

const int& LinkedList::operator[] (int index) const {
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

LinkedList LinkedList::operator+ (const LinkedList& other) const {
    LinkedList tmp_list;
    for (Node* tmp = head; tmp != nullptr; tmp = tmp->next) {
        tmp_list.push_back(tmp->value);
    }
    for (Node* tmp = other.head; tmp != nullptr; tmp = tmp->next) {
        tmp_list.push_back(tmp->value);
    }
    return tmp_list;
}

LinkedList& LinkedList::operator= (const LinkedList& rhs) {
    Node* tmp = rhs.head;
    while (tmp != nullptr) {
        push_back(tmp->value);
        tmp = tmp->next;
    }
    return *this;
}

const Node* LinkedList::center_node () const {
    Node* tmp = head;
    Node* tmp_x2 = head;
    while (tmp_x2 != nullptr && tmp_x2->next != nullptr) {
        tmp = tmp->next;
        tmp_x2 = tmp_x2->next->next;
    }
    return tmp;
}

bool LinkedList::has_cycle () const {
    Node* tmp = head;
    Node* tmp_x2 = head;
    if (head->next == nullptr)
        return false;
    while (tmp_x2 && tmp_x2->next) {
        tmp = tmp->next;
        tmp_x2 = tmp_x2->next->next;
        if (tmp == tmp_x2)
            return true;
    }
    return false;
}