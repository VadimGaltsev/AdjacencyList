#include <iostream>
#include <set>
#include <vector>
#include "AdjacencyList.h"


std::set<Node<int> > visited;

void deepSearch(AdjacencyList<int> &list, Node<int>& node) {
    visited.insert(node);
    for (int j = 0; j < list.size(); ++j) {
        Node<int> currentNode = list[j];
        if (visited.find(currentNode) == visited.end()) {
            deepSearch(list, currentNode);
        }
    }
}

int main() {
    Node<int> node1(1), node2(2), node3(3);
    AdjacencyList<int> list;
    list.insert(new Node<int>(0));
    list.insert(&node1);
    list.insert(0, &node2);
    list.insert(1, &node3);
    for (int i = 0; i < list.size(); ++i) {
        std::cout<< list[i].data << "\n";
    }

    deepSearch(list, node1);
    return 0;
}