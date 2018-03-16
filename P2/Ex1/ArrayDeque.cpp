/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayDeque.cpp
 * Author: mpedembe7.alumnes
 * 
 * Created on 6 / de març / 2018, 08:58
 */

#include "ArrayDeque.h"

ArrayDeque::ArrayDeque(int maxSize) {
    if(maxSize>0){
        this->data = vector(maxSize);
        this->front = 0;
        this->rear = 0;
        this->size = 0;
    }
    else throw invalid_argument("Atenció: aquest valor no és acceptat.");
}

ArrayDeque::~ArrayDeque() {
    data.clear();
    vector<int>().swap(data);
    delete data;
}

bool ArrayDeque::isEmpty() {
    return this->size==0;
}

bool ArrayDeque::isFull() {
    return this->size==this->data.size();
}

void ArrayDeque::insertFront(int element) {
    //TODO
}

void ArrayDeque::insertRear(int element) {
    //TODO
}

void ArrayDeque::deleteFront() {
    //TODO
}

void ArrayDeque::deleteRear() {
    //TODO
}

void ArrayDeque::print() {
    //TODO
}

int ArrayDeque::getFront() {
    return this->front;
}

int ArrayDeque::getRear() {
    return this->rear;
}
