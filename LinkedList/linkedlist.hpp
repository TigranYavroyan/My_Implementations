#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct Node {
    int value{};
    Node* next{nullptr};
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList ();
    LinkedList (const LinkedList& other);
    LinkedList (LinkedList&& rvalue);
    ~LinkedList ();
public:
    bool empty () const;
    bool has_cycle () const;
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
    const Node* center_node () const;
public:
    int& operator[] (int index);
    const int& operator[] (int index) const;
    LinkedList operator+ (const LinkedList& other) const;
    LinkedList& operator= (const LinkedList& rhs);
};

#include "linkedlist.cpp"

#endif