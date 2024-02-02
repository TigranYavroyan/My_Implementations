#include "linkedlist.hpp"

int main () {

    const Node *center_node = nullptr;
    LinkedList list;
    for (int i = 0; i <= 10; ++i) {
        list.push_back(i);
    }
    //list.push_front(10);
    list.display();
    // list.remove(5);
    // list.display();
    center_node = list.center_node();
    std::cout << center_node->value << ' ' << list.has_cycle() << std::endl;
    return 0;
}