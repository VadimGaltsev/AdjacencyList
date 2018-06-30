//
// Created by vadik on 24.06.2018.
//

#ifndef GRAPHS_NODE_H
#define GRAPHS_NODE_H

#include "AdjacencyList.h"

template <class T> class AdjacencyList;
template <class T>
class Node {
    friend class AdjacencyList<T>;
    Node<T> * next;
public:
    T data;
    Node(T data) : data(data) {
        next = nullptr;
    }
    bool operator < (const Node<T>& node2) const {
            return data < node2.data;
    }
};


#endif //GRAPHS_NODE_H
