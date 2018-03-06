/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayDeque.h
 * Author: mpedembe7.alumnes
 *
 * Created on 6 / de març / 2018, 08:58
 */

#ifndef ARRAYDEQUE_H
#define ARRAYDEQUE_H

#include<vector>
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
        int getReat() const;
    private:
        int size;
        std::vector<int> data ;
        int front;
        int rear;
};

#endif /* ARRAYDEQUE_H */

