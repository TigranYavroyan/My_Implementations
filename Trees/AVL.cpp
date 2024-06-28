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

template <typename T>void AVL<T>::insert(const std::initializer_list<T>& list) {
    this->_insert_from_IL(list);
}

template <typename T>
void AVL<T>::insert (const T& data) {
    this->m_root = _insert(data, this->m_root);
}

template <typename T>
template <typename func>
void AVL<T>::inorder (func f) {
    if (this->m_root == nullptr) return;
    this->_inorder(f, this->m_root);
}

template <typename T>template <typename func>
void AVL<T>::preorder (func f) {
    if (this->m_root == nullptr) return;
    this->_preorder(f, this->m_root);
}


template <typename T>
template <typename func>
void AVL<T>::postorder (func f) {
    if (this->m_root == nullptr) return;
    this->_postorder(f, this->m_root);
}

template <typename T>
T AVL<T>::find_min () const {
    if (this->m_root == nullptr)
    {
        std::cout << "There is no nodes" << std::endl;
        return T{};
    }
    return this->_find_min(this->m_root)->m_data;
}

template <typename T>
T AVL<T>::find_max () const {
    if (this->m_root == nullptr)
    {
        std::cout << "There is no nodes" << std::endl;
        return T{};
    }
    return this->_find_max(this->m_root)->m_data;
}

template <typename T>
int AVL<T>::height () const {
    return this->_height(this->m_root);
}

template <typename T>
size_t AVL<T>::size () const {
    return this->_size(this->m_root) - 1;
}

template <typename T>
bool AVL<T>::find (const T& data) const {
    if (this->m_root == nullptr) return false;
    return this->_find(data, this->m_root);
}

template <typename T>
void AVL<T>::remove (const T& data) {
    if (this->m_root == nullptr) return;
    this->m_root = _remove(data, this->m_root);
}

template <typename T>
T AVL<T>::successor (const T& data) const {
    node_type* res = this->_successor(_search(data, this->m_root));
    if (res) return res->m_data;
    return (res) ? res->m_data : throw std::invalid_argument("There is no successor");

}

template <typename T>
T AVL<T>::predecessor (const T& data) const {
    node_type* res = this->_predecessor(_search(data, this->m_root));
    return (res) ? res->m_data : throw std::invalid_argument("There is no predecessor");
}

template <typename T>
void AVL<T>::clear () noexcept {
    this->_clear(this->m_root);
    this->m_root = nullptr;
}

template <typename T>
AVL<T>::AVL (const std::initializer_list<T>& list) {
    this->_insert_from_IL(list);
}

template <typename T>
AVL<T>::~AVL () noexcept { clear(); }