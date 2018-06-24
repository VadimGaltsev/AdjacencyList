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
    Node<T> * currentNode;
    int nodePosition = 0;

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
    }

    ~AdjacencyList() {
        delete[] newArrayBuffer;
    }

    void insert(Node<T> *node) {
        if (position < currentSize) {
            arrayNode[position++] = node;
        } else {
            resize();
            arrayNode[position++] = node;
        }
    }

    void insert(int position, Node<T> *node) {
        if (position < currentSize) {
            Node<T> * endNode = arrayNode[position];
            node->next = endNode;
            arrayNode[position] = node;
            nodePosition += 1;
        } else {
            resize();
            Node<T> * endNode = arrayNode[position];
            node->next = endNode;
            arrayNode[position] = node;
            nodePosition += 1;
        }
    }

    int size() const {
        return position + nodePosition;
    }

    Node<T> &operator[](int position) {
        static int enter = 0;
        if (currentNode != nullptr) {
            if (currentNode->next != nullptr) {
                Node<T> *node = currentNode->next;
                currentNode = currentNode->next;
                ++enter;
                return *node;
            }
        }
        if (position == size() - 1) {
            int buffer = enter;
            enter = 0;
            currentNode = nullptr;
            return *arrayNode[position - buffer];
        }
        currentNode = arrayNode[position - enter];
        return *arrayNode[position - enter];

    };

};

#endif //GRAPHS_ADJACENCYLIST_H
