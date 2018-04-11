/*
 * TAD ArrayDeque amb una implementació amb array.
 */

/* 
 * File:   ArrayDeque.h
 * Author: Martí Pedemonte i Gabriel Marín
 *
 * Created on 6 / de març / 2018, 08:58
 */

#ifndef ARRAYDEQUE_H
#define ARRAYDEQUE_H

#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

class ArrayDeque {
    public:
        ArrayDeque(int maxSize);
        ~ArrayDeque();
        bool isEmpty() const;
        bool isFull() const;
        void insertFront(int element);
        void insertRear(int element);
        void deleteFront();
        void deleteRear();
        void print() const;
        int getFront() const;
        int getRear() const;
    private:
        int size; //comptador del nombre d'elements
        std::vector<int> data;
        int front;
        int rear;
};

#endif /* ARRAYDEQUE_H */

