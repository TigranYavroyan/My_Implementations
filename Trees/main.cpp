#include "AVL.hpp"
#include "BST.hpp"

int main () {
    std::initializer_list<int> il1 = {2, 1, -2, -5, -1, 5, 4, 8, 7, 9};
    std::initializer_list<int> il2 = {72, 73, 74, 66, 65, 69, 67, 70, 68};
    AVL<int> a_tree = il2;
    BST<int> tree = il2;
    tree.postorder([](const int val){std::cout << val << ' ';});
    std::cout << "\nThe height: " << tree.height() << '\n';
    a_tree.postorder([](const int val){std::cout << val << ' ';});
    std::cout << "\nThe height: " << a_tree.height() << '\n';
}