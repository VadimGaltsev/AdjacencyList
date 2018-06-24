#include <iostream>
#include "AdjacencyList.h"


int main() {

    AdjacencyList<int> list;
    list.insert(new Node<int>(1));
    list.insert(0, new Node<int>(3));
    list.insert(0, new Node<int>(5));
    list.insert(new Node<int>(4));
    list.insert(1, new Node<int>(6));
    list.insert(new Node<int>(20));
    list.insert(2, new Node<int>(32));
    list.insert(new Node<int>(10));
    list.insert(2, new Node<int>(666));
    list.insert(2, new Node<int>(5));
    list.insert(new Node<int>(4));
    list.insert(3, new Node<int>(6));
    list.insert(new Node<int>(20));
    list.insert(3, new Node<int>(32));
    list.insert(new Node<int>(10));
    list.insert(3, new Node<int>(666));

    for (int i = 0; i < list.size(); ++i) {
        std::cout<< list[i].data << "\n";
    }

    return 0;
}