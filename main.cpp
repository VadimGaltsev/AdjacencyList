#include <iostream>
#include "AdjacencyList.h"

int main() {
    AdjacencyList<int> list;
    list.insert(new Node<int>(1));
    list.insert(0, new Node<int>(3));
    list.insert(0, new Node<int>(5));
    list.insert(new Node<int>(4));
    list.insert(1, new Node<int>(6));
    list.insert(new Node<int>(7));
    list.insert(new Node<int>(8));
    list.insert(new Node<int>(9));
    list.insert(new Node<int>(10));
    list.insert(new Node<int>(11));
    for (int i = 0; i < list.size(); ++i) {
        std::cout<< list[i].data << "\n";
    }

    return 0;
}