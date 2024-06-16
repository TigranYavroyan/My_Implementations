#include "BST.hpp"

int main () {
    std::initializer_list il = {2, 1, -2, -5, -1, 5, 4, 8, 7, 9};
    BST<int> tree = il;
    tree.postorder([](const int val){std::cout << val << ' ';});
    std::cout << '\n';
    std::cout << tree.find_min() << std::endl;
}