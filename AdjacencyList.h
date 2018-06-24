//
// Created by vadik on 24.06.2018.
//

#ifndef GRAPHS_ADJACENCYLIST_H
#define GRAPHS_ADJACENCYLIST_H

#include <cstring>
#include <vector>
#include "Node.h"

class AdjacencyList {
private:
    Node ** arrayNode;
    int currentSize = 4;
    Node ** newArrayBuffer;
    int position = 0;
    void resize() {
        newArrayBuffer = new Node * [currentSize * 2];
        memcpy(newArrayBuffer, arrayNode, currentSize * sizeof(Node*));
        currentSize = currentSize * 2;
        delete[] arrayNode;
        arrayNode = newArrayBuffer;
    }
public:

    AdjacencyList() {
        arrayNode = new Node * [currentSize];
    }
    ~AdjacencyList() {
        delete [] newArrayBuffer;
    }
    void insert(Node * node) {
        if ( position < currentSize) {
            arrayNode[position++] = node;
        } else {
            resize();
            arrayNode[position++] = node;
        }
    }
    void insert(int position, Node * node) {
        if (position < currentSize) {
            Node * endNode = arrayNode[position];
            endNode->next = node;
            arrayNode[position] = node;
        } else {
            resize();
            Node * endNode = arrayNode[position];
            endNode->next = node;
            arrayNode[position] = node;        }
    }
    int size() const {
        return position;
    }

    Node& operator[](int position) {
        return *arrayNode[position];
    };

};


#endif //GRAPHS_ADJACENCYLIST_H
