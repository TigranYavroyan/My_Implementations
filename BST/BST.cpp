#include "BST.hpp"

template <typename T>
void BST<T>::_insert_from_IL(const std::initializer_list<T>& list) {
    for (const auto& val : list) {
        insert(val);
    }
}

template <typename T>
BST<T>::BST () = default;

template <typename T>
BST<T>::BST (const std::initializer_list<T>& list) {
    _insert_from_IL(list);
}

template <typename T>
BST<T>::~BST () noexcept { clear(); }

template <typename T>
void BST<T>::insert(const std::initializer_list<T>& list) {
    _insert_from_IL(list);
}

template <typename T>
void BST<T>::insert (const T& data) {
    if (m_root == nullptr) m_root = new Node(data);
    else _insert(data, m_root);
}

template <typename T>
void BST<T>::_insert (const T& data, Node*& curr) {
    if (curr == nullptr) curr = new Node(data);
    else if (curr->m_data < data) _insert(data, curr->m_right);
    else _insert(data, curr->m_left);
}

template <typename T>
template <typename func>
void BST<T>::inorder (func f) {
    if (m_root == nullptr) return;
    _inorder(f, m_root);
}

template <typename T>
template <typename func>
void BST<T>::_inorder (func f, Node* curr) {
    if (curr) {
        _inorder(f, curr->m_left);
        f(curr->m_data);
        _inorder(f, curr->m_right);
    }
}

template <typename T>
template <typename func>
void BST<T>::preorder (func f) {
    if (m_root == nullptr) return;
    _preorder(f, m_root);
}

template <typename T>
template <typename func>
void BST<T>::_preorder (func f, Node* curr) {
    if (curr) {
        f(curr->m_data);
        _preorder(f, curr->m_left);
        _preorder(f, curr->m_right);
    }
}

template <typename T>
template <typename func>
void BST<T>::postorder (func f) {
    if (m_root == nullptr) return;
    _postorder(f, m_root);
}

template <typename T>
template <typename func>
void BST<T>::_postorder (func f, Node* curr) {
    if (curr) {
        _postorder(f, curr->m_left);
        _postorder(f, curr->m_right);
        f(curr->m_data);
    }
}

template <typename T>
T BST<T>::find_min () const {
    if (m_root == nullptr)
    {
        std::cout << "There is no nodes" << std::endl;
        return 0;
    }
    return _find_min(m_root)->m_data;
}

template <typename T>
typename BST<T>::Node* BST<T>::_find_min (Node* curr) const {
    if (curr->m_left == nullptr) return curr;
    return _find_min(curr->m_left);
}

template <typename T>
T BST<T>::find_max () const {
    if (m_root == nullptr)
    {
        std::cout << "There is no nodes" << std::endl;
        return 0;
    }
    return _find_max(m_root)->m_data;
}

template <typename T>
typename BST<T>::Node* BST<T>::_find_max (Node* curr) const {
    if (curr->m_right == nullptr) return curr;
    return _find_max(curr->m_right);
}

template <typename T>
size_t BST<T>::height () const {
    return _height(m_root);
}

template <typename T>
size_t BST<T>::_height (Node* curr) const {
    if (curr == nullptr) return 0;
    size_t left_height = _height(curr->m_left);
    size_t right_height = _height(curr->m_right);
    return std::max(left_height, right_height) + 1;
}

template <typename T>
size_t BST<T>::size () const {
    return _size(m_root) - 1;
}

template <typename T>
size_t BST<T>::_size (Node* curr) const {
    if (curr == nullptr) return 1;
    else return _size(curr->m_left) + _size(curr->m_right);
}

template <typename T>
bool BST<T>::search (const T& data) const {
    if (m_root == nullptr) return false;
    return _search(data, m_root);
}

template <typename T>
bool BST<T>::_search (const T& data, Node* curr) const {
    if (curr == nullptr) return false;
    if (curr->m_data == data) return true;
    if (curr->m_data < data) return _search(data, curr->m_right);
    else return _search(data, curr->m_left);
}

template <typename T>
void BST<T>::remove (const T& data) {
    if (m_root == nullptr) return;
    m_root = _remove(data, m_root);
}

template <typename T>
typename BST<T>::Node* BST<T>::_remove (const T& data, Node*& curr) {
    if (curr == nullptr) return curr;
    if (curr->m_data > data) curr->m_left = _remove(data, curr->m_left);
    else if (curr->m_data < data) curr->m_right = _remove(data, curr->m_right);
    else {
        Node* tmp;
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
            tmp = _find_min(curr->m_right);
            curr->m_data = tmp->m_data;
            curr->m_right = _remove(tmp->m_data, curr->m_right);
        }
    }
    return curr;
}

template <typename T>
T BST<T>::successor (const T& data) const {
    
}

template <typename T>
T BST<T>::_successor (const T& data, Node* curr) const {

}

template <typename T>
T BST<T>::predecessor (const T& data) const {
    
}

template <typename T>
T BST<T>::_predecessor (const T& data, Node* curr) const {

}

template <typename T>
void BST<T>::clear () noexcept {
    _clear(m_root);
    m_root = nullptr;
}

template <typename T>
void BST<T>::_clear (Node*& curr) noexcept {
    if (curr) {
        _clear(curr->m_left);
        _clear(curr->m_right);
        delete curr;
    }
}