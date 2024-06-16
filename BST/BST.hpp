#ifndef BST_HPP
#define BST_HPP
#include <iostream>

template <typename T>
class BST
{
    private:
        struct Node
        {
            T m_data;
            Node* m_left;
            Node* m_right;
            Node() : m_left{nullptr}, m_right{nullptr} {}
            Node(const T& data) : m_left{nullptr}, m_right{nullptr}, m_data{data} {}
        };
        Node* m_root = nullptr;
        void _insert (const T&, Node*&);
        void _remove (const T&, Node*&);
        bool _search (const T&, Node*) const;
        void _inorder (Node*);
        void _preorder (Node*);
        void _postorder (Node*);
        T _find_min (Node*) const;
        T _find_max (Node*) const;
        T _successor (const T&, Node*) const;
        T _predecessor (const T&, Node*) const;
        unsigned long _height (Node*) const;
        unsigned long _size (Node*) const;
        bool _is_valid_BST (Node*) const;
        void _levl_order (Node*, unsigned long);
        void _serialize (Node*, T*&, unsigned long&) const;
    public:
        BST ();
        ~BST ();
        void insert (const T&);
        void remove (const T&);
        bool search (const T&) const;
        void inorder ();
        void preorder ();
        void postorder ();
        T find_min () const;
        T find_max () const;
        T successor (const T&) const;
        T predecessor (const T&) const;
        unsigned long height () const;
        unsigned long size () const;
        bool is_valid_BST () const;
        void levl_order ();
        void clear ();
        T* serialize () const;
        BST copy () const;
        void update (const T&, const T&);
        void rangeQuery (const T&, const T&);
        T kthSmallest (unsigned long) const;
        T kthLargest (unsigned long) const;
};

#include "BST.cpp"

#endif // BST_HPP