#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

class LinkedList {
public:
    LinkedList ();
    LinkedList (const LinkedList& other);
    LinkedList (LinkedList&& rvalue);
    ~LinkedList ();
public:
    bool empty () const;
    void push_back (int n);
    void push_front (int n);
    void display () const;
    void erase ();
    void pop_back ();
    void pop_front ();
    void insert (int index, int data);
    void remove (int data);
    int get (int index) const;
    int size () const;
public:
    int& operator[] (int index);
    const int& operator[] (int index) const;
    LinkedList operator+ (const LinkedList& other) const;
    LinkedList& operator= (const LinkedList& rhs);
private:
    struct Node {
        int value{};
        Node* next{nullptr};
    };
    Node* head;
};

#include "linkedlist.cpp"

#endif