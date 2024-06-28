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
};

#include "BST.cpp"

#endif // BST_HPP