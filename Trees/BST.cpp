#include "BST.hpp"

template <typename T>
typename BST<T>::node_type* BST<T>::_insert (const T& data, node_type* curr) {
    if (curr == nullptr) return new node_type(data);
    else if (curr->m_data < data) curr->m_right = _insert(data, curr->m_right);
    else curr->m_left = _insert(data, curr->m_left);

    return curr;
}

template <typename T>
typename BST<T>::node_type* BST<T>::_remove (const T& data, node_type* curr) {
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

    return curr;
}

template <typename T>void BST<T>::insert(const std::initializer_list<T>& list) {
    this->_insert_from_IL(list);
}

template <typename T>
void BST<T>::insert (const T& data) {
    this->m_root = _insert(data, this->m_root);
}

template <typename T>
template <typename func>
void BST<T>::inorder (func f) {
    if (this->m_root == nullptr) return;
    this->_inorder(f, this->m_root);
}

template <typename T>template <typename func>
void BST<T>::preorder (func f) {
    if (this->m_root == nullptr) return;
    this->_preorder(f, this->m_root);
}


template <typename T>
template <typename func>
void BST<T>::postorder (func f) {
    if (this->m_root == nullptr) return;
    this->_postorder(f, this->m_root);
}

template <typename T>
T BST<T>::find_min () const {
    if (this->m_root == nullptr)
    {
        std::cout << "There is no nodes" << std::endl;
        return T{};
    }
    return this->_find_min(this->m_root)->m_data;
}

template <typename T>
T BST<T>::find_max () const {
    if (this->m_root == nullptr)
    {
        std::cout << "There is no nodes" << std::endl;
        return T{};
    }
    return this->_find_max(this->m_root)->m_data;
}

template <typename T>
int BST<T>::height () const {
    return this->_height(this->m_root);
}

template <typename T>
size_t BST<T>::size () const {
    return this->_size(this->m_root) - 1;
}

template <typename T>
bool BST<T>::find (const T& data) const {
    if (this->m_root == nullptr) return false;
    return this->_find(data, this->m_root);
}

template <typename T>
void BST<T>::remove (const T& data) {
    if (this->m_root == nullptr) return;
    this->m_root = _remove(data, this->m_root);
}

template <typename T>
T BST<T>::successor (const T& data) const {
    node_type* res = this->_successor(_search(data, this->m_root));
    if (res) return res->m_data;
    return (res) ? res->m_data : throw std::invalid_argument("There is no successor");

}

template <typename T>
T BST<T>::predecessor (const T& data) const {
    node_type* res = this->_predecessor(_search(data, this->m_root));
    return (res) ? res->m_data : throw std::invalid_argument("There is no predecessor");
}

template <typename T>
void BST<T>::clear () noexcept {
    this->_clear(this->m_root);
    this->m_root = nullptr;
}

template <typename T>
BST<T>::BST (const std::initializer_list<T>& list) {
    this->_insert_from_IL(list);
}

template <typename T>
BST<T>::~BST () noexcept { clear(); }