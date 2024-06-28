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
};

#include "AVL.cpp"

#endif // AVL_HPP