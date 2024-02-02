#include "DoublyLinkedList.hpp"

int main () {
    Dlist list;
    Dlist list2;
    for (int i = 1; i <= 10; ++i) {
        list.push_back(i);
        list2.push_back(i * 2);
    }
    Dlist list3 = list + list2;
    list3.display();
}