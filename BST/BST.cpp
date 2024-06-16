#include "BST.hpp"

template <typename T>
BST<T>::BST() = default;

template <typename T>
BST<T>::~BST() { clear(); }


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
void BST<T>::inorder () {
    _inorder(m_root);
}

template <typename T>
void BST<T>::_inorder (Node* curr) {
    if (curr) {
        _inorder(curr->m_left);
        std::cout << curr->m_data << ' ';
        _inorder(curr->m_right);
    }
}

template <typename T>
void BST<T>::clear () {

}