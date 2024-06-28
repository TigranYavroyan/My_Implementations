#include "A_BST.hpp"

template <typename T>
void A_BST<T>::_insert_from_IL(const std::initializer_list<T>& list) {
    for (const auto& val : list) {
        insert(val);
    }
}

template <typename T>void A_BST<T>::insert(const std::initializer_list<T>& list) {
    _insert_from_IL(list);
}

template <typename T>
void A_BST<T>::insert (const T& data) {
    m_root = _insert(data, m_root);
}

template <typename T>
template <typename func>
void A_BST<T>::inorder (func f) {
    if (m_root == nullptr) return;
    _inorder(f, m_root);
}

template <typename T>
template <typename func>
void A_BST<T>::_inorder (func f, Node* curr) {    
    if (curr) {
        _inorder(f, curr->m_left);
        f(curr->m_data);
        _inorder(f, curr->m_right);
    }
}
template <typename T>template <typename func>
void A_BST<T>::preorder (func f) {
    if (m_root == nullptr) return;
    _preorder(f, m_root);
}

template <typename T>
template <typename func>
void A_BST<T>::_preorder (func f, Node* curr) {
    if (curr) {
        f(curr->m_data);
        _preorder(f, curr->m_left);
        _preorder(f, curr->m_right);
    }
}

template <typename T>
template <typename func>
void A_BST<T>::postorder (func f) {
    if (m_root == nullptr) return;
    _postorder(f, m_root);
}

template <typename T>
template <typename func>
void A_BST<T>::_postorder (func f, Node* curr) {
    if (curr) {
        _postorder(f, curr->m_left);
        _postorder(f, curr->m_right);
        f(curr->m_data);
    }
}

template <typename T>
T A_BST<T>::find_min () const {
    if (m_root == nullptr)
    {
        std::cout << "There is no nodes" << std::endl;
        return T{};
    }
    return _find_min(m_root)->m_data;
}

template <typename T>
typename A_BST<T>::Node* A_BST<T>::_find_min (Node* curr) const {
    if (curr->m_left == nullptr) return curr;
    return _find_min(curr->m_left);
}

template <typename T>
T A_BST<T>::find_max () const {
    if (m_root == nullptr)
    {
        std::cout << "There is no nodes" << std::endl;
        return T{};
    }
    return _find_max(m_root)->m_data;
}

template <typename T>
typename A_BST<T>::Node* A_BST<T>::_find_max (Node* curr) const {
    if (curr->m_right == nullptr) return curr;
    return _find_max(curr->m_right);
}

template <typename T>
int A_BST<T>::height () const {
    return _height(m_root);
}

template <typename T>
int A_BST<T>::_height (Node* curr) const {
    if (curr == nullptr) return -1;
    int left_height = _height(curr->m_left);
    int right_height = _height(curr->m_right);
    return std::max(left_height, right_height) + 1;
}

template <typename T>
size_t A_BST<T>::size () const {
    return _size(m_root) - 1;
}

template <typename T>
size_t A_BST<T>::_size (Node* curr) const {
    if (curr == nullptr) return 1;
    else return _size(curr->m_left) + _size(curr->m_right);
}

template <typename T>
bool A_BST<T>::find (const T& data) const {
    if (m_root == nullptr) return false;
    return _find(data, m_root);
}

template <typename T>
bool A_BST<T>::_find (const T& data, Node* curr) const {
    if (curr == nullptr) return
false;
    if (curr->m_data == data) return true;
    if (curr->m_data < data) return _find(data, curr->m_right);
    else return _find(data, curr->m_left);
}

template <typename T>
void A_BST<T>::remove (const T& data) {
    if (m_root == nullptr) return;
    m_root = _remove(data, m_root);
}

template <typename T>
typename A_BST<T>::Node* A_BST<T>::_search(const T& data, Node* curr) const {
    if (curr == nullptr) return curr;
    if (curr->m_data == data) return curr;
    if (curr->m_data < data) return _search(data, curr->m_right);
    else return _search(data, curr->m_left);
}

template <typename T>
T A_BST<T>::successor (const T& data) const {
    Node* res = _successor(_search(data, m_root));
    if (res) return res->m_data;
    return (res) ? res->m_data : throw std::invalid_argument("There is no successor");

}

template <typename T>
typename A_BST<T>::Node* A_BST<T>::_successor (Node* curr) const {
    if (curr == nullptr || curr->m_right == nullptr) return 0;
    return _find_min(curr->m_right);
}

template <typename T>
T A_BST<T>::predecessor (const T& data) const {
    Node* res = _predecessor(_search(data, m_root));
    return (res) ? res->m_data : throw std::invalid_argument("There is no predecessor");
}

template <typename T>
typename A_BST<T>::Node* A_BST<T>::_predecessor (Node* curr) const {
    if (curr == nullptr || curr->m_left == nullptr) return 0;
    return _find_max(curr->m_left);
}

template <typename T>
void A_BST<T>::clear () noexcept {
    _clear(m_root);
    m_root = nullptr;
}

template <typename T>
void A_BST<T>::_clear (Node*& curr) noexcept {
    if (curr) {
        _clear(curr->m_left);
        _clear(curr->m_right);
        delete curr;
    }
}