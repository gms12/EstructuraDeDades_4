/*
 * Mètodes implementats del TAD ArrayDeque.
 */

/* 
 * File:   ArrayDeque.cpp
 * Author: Martí Pedemonte i Gabriel Marín
 * 
 * Created on 6 / de març / 2018, 08:58
 */

#include "ArrayDeque.h"

ArrayDeque::ArrayDeque(int maxSize) {
    if(maxSize>0){
        vector<int> d (maxSize);
        this->data = d;
        this->front = 0;
        this->rear = 0;
        this->size = 0;
    }
    else throw invalid_argument("Atenció: aquest valor no és acceptat.");
    cout << "Creada ArrayDeque de mida " << data.size() << endl;
}

ArrayDeque::~ArrayDeque() {
    data.clear();
    vector<int>().swap(data);
    delete &data;
}

bool ArrayDeque::isEmpty() const {
    return this->size == 0;
}//comprovem que el comptador sigui 0

bool ArrayDeque::isFull() const {
    return this->size == this->data.size();
}//comprovem que el comptador sigui el mateix nombre que la mida de l'array

void ArrayDeque::insertFront(int element) {
    if(!this->isFull()){
        if(!this->isEmpty())front = (data.size() + front-1)%data.size();
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
        if(!this->isEmpty())rear = (data.size() + rear+1)%data.size();
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
        else front = (data.size() + front+1)%data.size();
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
        else rear = (data.size() + rear-1)%data.size();
        size--;
    }
    else throw invalid_argument("L'Array és buida.");
}

void ArrayDeque::print() const {
    cout << "[";
    for(int i = front; i<front+size; i++){
        cout << this->data[(i)%data.size()];
        if(i < front+size-1) cout << ", ";
    }
    cout << "]" << endl;

}

int ArrayDeque::getFront() const {
    if(!this->isEmpty()){
        return this->data[front];
    }
    else throw invalid_argument("L'Array és buida.");
    return 0;    
}

int ArrayDeque::getRear() const {
    if(!this->isEmpty()){
        return this->data[rear];
    }
    else throw invalid_argument("L'Array és buida.");
    return 0;  
}
