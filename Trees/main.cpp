#include "AVL.hpp"
#include "BST.hpp"

int main () {
    std::initializer_list<int> il1 = {2, 1, -2, -5, -1, 5, 4, 8, 7, 9};
    std::initializer_list<int> il2 = {72, 73, 74, 66, 65, 69, 67, 70, 68};
	std::initializer_list<int> succ_pred = {50, 100, 150, 125, 124, 123, 116, 117, 118, 119, 122, 121, 120};

    AVL<int> a_tree = il2;
    BST<int> tree = il1;

    tree.postorder([](const int val){std::cout << val << ' ';});
    std::cout << "\nThe height: " << tree.height() << '\n';

	std::cout << tree.predecessor(-1) << std::endl;
	std::cout << tree.successor(5) << std::endl;
}