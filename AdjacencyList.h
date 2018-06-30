//
// Created by vadik on 24.06.2018.
//

#ifndef GRAPHS_ADJACENCYLIST_H
#define GRAPHS_ADJACENCYLIST_H

#include <cstring>
#include "Node.h"


template<class T>
class AdjacencyList {
private:

    Node<T> **arrayNode;
    int currentSize = 4;
    Node<T> **newArrayBuffer;
    int position = 0;
    mutable Node<T> * currentNode;
    int nodePosition = 0;
    mutable int enter = 0;
    void resize() {
        newArrayBuffer = new Node<T> *[currentSize * 2];
        memcpy(newArrayBuffer, arrayNode, currentSize * sizeof(Node<T> *));
        currentSize = currentSize * 2;
        delete[] arrayNode;
        arrayNode = newArrayBuffer;
    }

public:

    AdjacencyList() {
        arrayNode = new Node<T> *[currentSize];
        currentNode = nullptr;
        newArrayBuffer = nullptr;
    }

    void insert(Node<T> *node) {
        if (position == currentSize) {
            resize();
        }
        arrayNode[position++] = node;
    }

    void insert(int position, Node<T> *node) {
        if (position == currentSize) {
            resize();
        }
        Node<T> * endNode = arrayNode[position];
        node->next = endNode;
        arrayNode[position] = node;
        nodePosition += 1;
    }

    int size() const {
        return position + nodePosition;
    }

    Node<T> &operator[](int position) const {
        if (position == 0) enter = 0;
        //TODO add search of needed position in list with ptr > array size
        if (currentNode != nullptr) {
            if (currentNode->next != nullptr) {
                Node<T> *node = currentNode->next;
                currentNode = currentNode->next;
                ++enter;
                if (position == size() - 1) {
                    int buffer = enter;
                    enter = 0;
                    currentNode = nullptr;
                }
                return *node;
            }
        }
        currentNode = arrayNode[position - enter];
        return *arrayNode[position - enter];
    };

    ~AdjacencyList() {
        if (newArrayBuffer != arrayNode) {
            delete[] arrayNode;
        }
        if (newArrayBuffer != nullptr)
        delete[] newArrayBuffer;
    }

};

#endif //GRAPHS_ADJACENCYLIST_H
