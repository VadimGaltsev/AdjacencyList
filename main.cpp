#include <iostream>
#include <vector>
#include "AdjacencyList.h"



int main() {
    AdjacencyList<int> list;
    list.insert(new Node<int>(1));
    list.insert(0, new Node<int>(3));
    list.insert(0, new Node<int>(5));
    list.insert(new Node<int>(4));
    for (int i = 0; i < list.size(); ++i) {
        std::cout<< list[i].data << "\n";
    }

    return 0;
}