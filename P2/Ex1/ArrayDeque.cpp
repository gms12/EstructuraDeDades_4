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
    return this->size == 0;
}//comprovem que el comptador sigui 0

bool ArrayDeque::isFull() {
    return this->size == this->data.size();
}//comprovem que el comptador sigui el mateix nombre que la mida de l'array

void ArrayDeque::insertFront(int element) {
    if(!this->isFull()){
        if(!this->isEmpty())front = (front-1)%data.size();
        /*en el cas del front tirem cap enrere per tal de mantenir-me sempre
         al davant.*/
        data[front] = element;
        size++;
    }
    else throw invalid_argument("L'Array és plena.");
    //si l'array és plena no es pot afegir cal element.
}

void ArrayDeque::insertRear(int element) {
    if(!this->isFull()){
        if(!this->isEmpty())rear = (rear+1)%data.size();
        /*En el cas d'estar buida, front=rear=0. Inserir l'element davant o 
         darrera és indiferent.*/
        data[rear]=element;
        size++;
    }
    else throw invalid_argument("L'Array és plena.");
}

void ArrayDeque::deleteFront() {
    if(!this->isEmpty()){
        if(size == 1){
            front = 0;
            rear = 0;
        }
        /*en el cas de només tenir un element, portem els dos valors a 0,
         valors inicials.*/
        else front = (front+1)%data.size();
        size--;
    }
    else throw invalid_argument("L'Array és buida.");
}

void ArrayDeque::deleteRear() {
    if(!this->isEmpty()){
        if(size == 1){
            front = 0;
            rear = 0;
        }
        else rear = (rear-1)%data.size();
        size--;
    }
    else throw invalid_argument("L'Array és buida.");
}

void ArrayDeque::print() {
    cout << "[";
    for(int i = front; i<front+size; i++){
        cout << this->data[(i)%data.size()];
        if(i < front+size-1) cout << ", ";
    }
    cout << "]";
}

int ArrayDeque::getFront() {
    if(!this->isEmpty()){
        return this->data[front];
    }
    else throw invalid_argument("L'Array és buida.");
    return 0;    
}

int ArrayDeque::getRear() {
    if(!this->isEmpty()){
        return this->data[rear];
    }
    else throw invalid_argument("L'Array és buida.");
    return 0;  
}
