#include "AVL.hpp"

template <typename T>
typename AVL<T>::node_type* AVL<T>::_left_rotate (node_type* z) { // RR
    node_type* y = z->m_right;
    node_type* T2 = y->m_left;
    z->m_right = T2;
    y->m_left = z;
    return y;
}

template <typename T>
typename AVL<T>::node_type* AVL<T>::_right_rotate (node_type* z) { // RR
    node_type* y = z->m_left;
    node_type* T3 = y->m_right;
    z->m_left = T3;
    y->m_right = z;
    return y;
}

template <typename T>
int AVL<T>::_get_BF (node_type* curr) {
    return (this->_height(curr->m_left) - this->_height(curr->m_right));
}

template <typename T>
typename AVL<T>::node_type* AVL<T>::_insert (const T& data, node_type* curr) {
    if (curr == nullptr) return new node_type(data);
    else if (curr->m_data < data) curr->m_right = _insert(data, curr->m_right);
    else curr->m_left = _insert(data, curr->m_left);

    int bf = _get_BF(curr);
    if (bf > 1 && data <= curr->m_left->m_data) // LL
        return _right_rotate(curr);
    if (bf > 1 && data > curr->m_left->m_data) // LR
    {
        curr->m_left = _left_rotate(curr->m_left);
        return _right_rotate(curr);
    }
    if (bf < -1 && data > curr->m_right->m_data) // RR
        return _left_rotate(curr);
    if (bf < -1 && data <= curr->m_right->m_data) // RL
    {
        curr->m_right = _right_rotate(curr->m_right);
        return _left_rotate(curr);
    }
    return curr;
}

template <typename T>
typename AVL<T>::node_type* AVL<T>::_remove (const T& data, node_type* curr) {
    if (curr == nullptr) return curr;
    if (curr->m_data > data) curr->m_left = _remove(data, curr->m_left);
    else if (curr->m_data < data) curr->m_right = _remove(data, curr->m_right);
    else {
        node_type* tmp;
        if (curr->m_left == nullptr) {
            tmp = curr->m_right;
            delete curr;
            return tmp;
        }
        else if (curr->m_right == nullptr) {
            tmp = curr->m_left;
            delete curr;
            return tmp;
        }
        else {
            tmp = this->_find_min(curr->m_right);
            curr->m_data = tmp->m_data;
            curr->m_right = _remove(tmp->m_data, curr->m_right);
        }
    }

    int bf = _get_BF(curr);
    if (bf > 1 && _get_BF(curr->m_left) >= 0) // LL
        return _right_rotate(curr);
    if (bf > 1 && _get_BF(curr->m_left) < 0) // LR
    {
        curr->m_left = _left_rotate(curr->m_left);
        return _right_rotate(curr);
    }
    if (bf < -1 && _get_BF(curr->m_right) <= 0) // RR
        return _left_rotate(curr);
    if (bf < -1 && _get_BF(curr->m_right) > 0) // RL
    {
        curr->m_right = _right_rotate(curr->m_right);
        return _left_rotate(curr);
    }

    return curr;
}

template <typename T>
AVL<T>::AVL (const std::initializer_list<T>& list) {
    this->_insert_from_IL(list);
}

template <typename T>
AVL<T>::~AVL () noexcept { this->_clear(this->m_root); }