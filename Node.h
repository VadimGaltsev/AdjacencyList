//
// Created by vadik on 24.06.2018.
//

#ifndef GRAPHS_NODE_H
#define GRAPHS_NODE_H

template <class D> class AdjacencyList;

template <class T>
class Node {
    friend class AdjacencyList<T>;
    Node<T> * next;
public:
    T data;
    Node(T data) : data(data) {
        next = nullptr;
    }
};


#endif //GRAPHS_NODE_H
