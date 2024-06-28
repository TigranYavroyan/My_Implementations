#ifndef AVL_HPP
#define AVL_HPP

#include "A_BST.hpp"

template <typename T>
class AVL : public A_BST<T> {
private:
    using node_type = typename A_BST<T>::Node;

    node_type* _left_rotate (node_type* z);
    node_type* _right_rotate (node_type* z);
    int       _get_BF(node_type* curr);

    node_type* _insert(const T&, node_type*) override;
    node_type* _remove(const T&, node_type*) override;
public:
    AVL () = default;
    AVL (const std::initializer_list<T>&);
    ~AVL () noexcept;

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
    int height () const;
    size_t size () const;
    void clear () noexcept;
};

#include "AVL.cpp"

#endif // AVL_HPP