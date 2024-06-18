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

// helpers
    Node* _search (const T&, Node*) const;
    void _insert_from_IL (const std::initializer_list<T>&);

    void _insert (const T&, Node*&);
    Node* _remove (const T&, Node*&);
    bool _find (const T&, Node*) const;

    template <typename func>
    void _inorder (func f, Node*);

    template <typename func>
    void _preorder (func f, Node*);

    template <typename func>
    void _postorder (func f, Node*);

    Node* _find_min (Node*) const;
    Node* _find_max (Node*) const;
    Node* _successor (Node*) const;
    Node* _predecessor (Node*) const;
    size_t _height (Node*) const;
    size_t _size (Node*) const;
    void _clear(Node*&) noexcept;
public:
    BST ();
    ~BST () noexcept;
    BST (const std::initializer_list<T>&);
    void insert (const T&);
    void insert (const std::initializer_list<T>&);
    void remove (const T&);
    bool find (const T&) const;

    template <typename func>
    void inorder (func f);

    template <typename func>
    void preorder (func f);

    template <typename func>
    void postorder (func f);

    T find_min () const;
    T find_max () const;
    T successor (const T&) const;
    T predecessor (const T&) const;
    size_t height () const;
    size_t size () const;
    void clear () noexcept;
};

#include "BST.cpp"

#endif // BST_HPP