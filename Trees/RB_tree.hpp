#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include "A_BST.hpp"

template <typename T>
class RB_tree final : public A_BST<T, RB_Node<T> > {
public:
    using node_type = RB_Node<T>;
    using node_pointer = RB_Node<T>*;
private:

};

#include "RB_tree.cpp"

#endif // RB_TREE_HPP