#ifndef BST_HPP
#define BST_HPP

#include "A_BST.hpp"

template <typename T>
class BST : public A_BST<T> {
private:
    using node_type = typename A_BST<T>::Node;

    node_type* _insert(const T&, node_type*) override;
    node_type* _remove(const T&, node_type*) override;
public:
    BST () = default;
    BST (const std::initializer_list<T>&);
    virtual ~BST () noexcept;
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

#include "BST.cpp"

#endif // BST_HPP