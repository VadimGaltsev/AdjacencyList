//
// Created by vadik on 24.06.2018.
//

#ifndef GRAPHS_ADJACENCYLIST_H
#define GRAPHS_ADJACENCYLIST_H

#include <cstring>
#include <vector>
#include "Node.h"
template <class T>
class AdjacencyList {
private:
    Node<T> ** arrayNode;
    int currentSize = 4;
    Node<T> ** newArrayBuffer;
    int position = 0;
    void resize() {
        newArrayBuffer = new Node<T> * [currentSize * 2];
        memcpy(newArrayBuffer, arrayNode, currentSize * sizeof(Node<T>*));
        currentSize = currentSize * 2;
        delete[] arrayNode;
        arrayNode = newArrayBuffer;
    }
public:

    AdjacencyList() {
        arrayNode = new Node<T> * [currentSize];
    }
    ~AdjacencyList() {
        delete [] newArrayBuffer;
    }
    void insert(Node<T> * node) {
        if ( position < currentSize) {
            arrayNode[position++] = node;
        } else {
            resize();
            arrayNode[position++] = node;
        }
    }
    void insert(int position, Node<T> * node) {
        if (position < currentSize) {
            Node<T> * endNode = arrayNode[position];
            endNode->next = node;
            arrayNode[position] = node;
        } else {
            resize();
            Node<T> * endNode = arrayNode[position];
            endNode->next = node;
            arrayNode[position] = node;        }
    }
    int size() const {
        return position;
    }

    Node<T>& operator[](int position) {
        return *arrayNode[position];
    };

};


#endif //GRAPHS_ADJACENCYLIST_H
