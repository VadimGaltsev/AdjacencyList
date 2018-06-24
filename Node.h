//
// Created by vadik on 24.06.2018.
//

#ifndef GRAPHS_NODE_H
#define GRAPHS_NODE_H
class AdjacencyList;

class Node {
    friend class AdjacencyList;
    Node * next;
public:
    int data;
    Node(int data) : data(data) {
        next = nullptr;
    }
};


#endif //GRAPHS_NODE_H
