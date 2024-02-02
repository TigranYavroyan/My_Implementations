#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#define private public

class Dlist {
public:
    Dlist ();
    Dlist (const Dlist& other);
    Dlist (Dlist&& other);
    ~Dlist ();
public:
    bool empty () const;
    void push_back (int value);
    void push_front (int value);
    void display () const;
    void erase ();
    void pop_back ();
    void pop_front ();
    void remove (int data);
    void insert (unsigned int index, int data);
    unsigned int size () const;
    int get (unsigned int index) const;
public:
    Dlist& operator= (const Dlist& rhs);
    const Dlist& operator= (Dlist&& rhs);
    Dlist operator+ (const Dlist& rhs) const;
    int& operator[] (int index);
    const int& operator[] (int index) const;
    bool operator== (const Dlist& rhs) const;
private:
    struct Node {
    int value{};
    Node *next{nullptr};
    Node *prev{nullptr};
};
    Node* head{nullptr};
    Node* tail{nullptr};
};

#include "DoublyLinkedList.cpp"

#endif // DOUBLYLINKEDLIST_H