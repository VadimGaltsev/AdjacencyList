#include <iostream>
#include "AdjacencyList.h"

int main() {
    AdjacencyList list;
    list.insert(new Node(1));
    list.insert(0, new Node(3));
    list.insert(0, new Node(5));
    list.insert(new Node(4));
    list.insert(1, new Node(6));
    list.insert(new Node(7));
    list.insert(new Node(8));
    list.insert(new Node(9));
    list.insert(new Node(10));
    list.insert(new Node(11));
    for (int i = 0; i < list.size(); ++i) {
        std::cout<< list[i].data << "\n";
    }

    return 0;
}