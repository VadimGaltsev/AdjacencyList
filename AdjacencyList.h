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
        int ptr = 0;
        Node<T>* current = nullptr;
        if (position >= size()) {
            throw ArraySizeException("List Index Out Of Bounds Exception");
        }
        for (int i = 0; i < this->position; ++i) {
            current = arrayNode[i];
            Node<T>* current_in = current;
            while (ptr < position && current_in != nullptr) {
                current_in = current_in->next;
                    ptr++;
            }
            if (ptr <= position && current_in != nullptr) {
                current = current_in;
                break;
            }
        }
        return *current;


    };

    class ArraySizeException {
    public:
        ArraySizeException(std::string d) {
            std::cerr << d << "\n";
        }
    };

    ~AdjacencyList() {
        if (newArrayBuffer != arrayNode) {
            delete[] arrayNode;
        }
        if (newArrayBuffer != nullptr)
        delete[] newArrayBuffer;
    }

};


//        if (position == 0) {
//            enter = 0;
//            currentNode = nullptr;
//        }
//        //TODO add search of needed position in list with ptr > array size
//        if (currentNode != nullptr) {
//            if (currentNode->next != nullptr) {
//                Node<T> *node = currentNode->next;
//                currentNode = currentNode->next;
//                ++enter;
//                if (position == size() - 1) {
//                    int buffer = enter;
//                    enter = 0;
//                    currentNode = nullptr;
//                }
//                return *node;
//            }
//        }
//        currentNode = arrayNode[position - enter];
//        return *arrayNode[position - enter];

#endif //GRAPHS_ADJACENCYLIST_H
