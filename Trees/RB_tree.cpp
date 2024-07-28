#include "RB_tree.hpp"

template <typename T>
RB_tree<T>::RB_tree (const std::initializer_list<T>& list) {
    _insert_from_IL(list);
}

template <typename T>
RB_tree<T>::~RB_tree () noexcept { 
    // this->_clear(this->m_root);
}

template <typename T>
typename RB_tree<T>::node_pointer RB_tree<T>::_left_rotate (node_pointer x) {
    node_pointer y = x->m_right;
    x->m_right = y->m_left;

    if (y->m_left != nullptr)
        y->m_left->m_parent = x;
    y->m_parent = x->m_parent;

    if (x->m_parent == nullptr)
        this->m_root = y;
    else if (x->m_parent->m_left == x)
        x->m_parent->m_left = y;
    else
        x->m_parent->m_right = y;

    y->left = x;
    x->m_parent = y;
    return y;
}

template <typename T>
typename RB_tree<T>::node_pointer RB_tree<T>::_right_rotate (node_pointer x) {
    node_pointer y = x->m_left;
    x->m_left = y->m_right;
    if (y->m_right != nullptr)
        y->m_right->m_parent = x;
    y->m_parent = x->m_parent;

    if (x->m_parent == nullptr)
        this->m_root = y;
    else if (x->m_parent->left == x)
        x->m_parent->m_left = y;
    else
        x->m_parent->m_right = y;

    y->m_right = x;
    x->m_parent = y;
    return y;
}

template <typename T>
void RB_tree<T>::_insert_fix_up (node_pointer curr) {

}

template <typename T>
typename RB_tree<T>::node_pointer RB_tree<T>::_insert (const T& data, node_pointer curr) {
    node_pointer y = nullptr; // y will be prev of curr
    node_pointer to_add = new node_type(data);
    
    while (curr != nullptr) {
        y = curr;
        if (curr->m_data > data) curr = curr->m_left;
        else curr = curr->m_right;
    }


    to_add->m_parent = y;

    if (y == nullptr) return to_add;
    else if (y->m_data >= data) y->m_left = to_add;
    else y->m_right = to_add;
    
    // _insert_fix_up(to_add);

    return this->m_root;
}

template <typename T>
typename RB_tree<T>::node_pointer RB_tree<T>::_remove (const T& data, node_pointer curr) {

}