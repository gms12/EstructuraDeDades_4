/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedDeque.h
 * Author: Gabriel
 *
 * Created on 20 de marzo de 2018, 8:35
 */

#ifndef LINKEDDEQUE_H
#define LINKEDDEQUE_H
#include "Node.h"

template <class Element> class LinkedDeque {
    public:
        LinkedDeque();
        ~LinkedDeque();
        LinkedDeque(const LinkedDeque<Element>& deque); 
        bool isEmpty()const;
        void insertFront(const Element & element); 
        void insertRear(const Element & element);
        void deleteFront();
        void deleteRear();
        void print();
        const Element& getFront()const;
        const Element& getRear()const;
    private:
        Node<Element> *_front; 
        Node<Element> *_rear; 
        int num_elements;
};

template <class Element> LinkedDeque::LinkedDeque() {
    //TODO
}

template <class Element> LinkedDeque::LinkedDeque(LinkedDeque<Element>& deque) {
    //TODO
}

template <class Element> LinkedDeque::~LinkedDeque() {
    //TODO
}
template <class Element> bool LinkedDeque::isEmpty() const{
    //TODO
}
template <class Element> void LinkedDeque::insertFront(const Element& element){
    //TODO
}
template <class Element> void LinkedDeque::insertRear(const Element& element){
    //TODO
}
template <class Element> void LinkedDeque::deleteFront(){
    //TODO
}
template <class Element> void LinkedDeque::deleteRear(){
    //TODO
}
template <class Element> void LinkedDeque::print(){
    //TODO
}        
template <class Element> const Element& LinkedDeque::getFront() const{
    //TODO
}
template <class Element> const Element& LinkedDeque::getRear() const{
    //TODO
}

#endif /* LINKEDDEQUE_H */

