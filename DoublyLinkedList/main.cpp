#include "DoublyLinkedList.hpp"

int main () {
    Dlist list;
    for (int i = 1; i <= 10; ++i) {
        list.push_back(i);
    }
    list.display();
    Dlist list2 = list;
    list2.erase();
    list2.display();
}