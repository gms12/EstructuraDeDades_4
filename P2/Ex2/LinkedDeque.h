/*
 * TAD LinkedDeque amb una estructura enllaçada.
 */

/* 
 * File:   LinkedDeque.h
 * Author: Martí Pedemonte i Gabriel Marín
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
        int size()const;
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
//Constructor per defecte. Creem els "fantasmes" i hi apuntem els punters 
//front i rear.
template <class Element> LinkedDeque::LinkedDeque() {
    Node<Element> f1=new Node<Element>();
    Node<Element> f2=new Node<Element>();
    this->_front=&f1;
    this->_rear=&f2;
    f1.setNext(this->_rear);
    f2.setPrevious(this->_front);
}

template <class Element> LinkedDeque::LinkedDeque(LinkedDeque<Element>& deque) {
    //TODO
}

template <class Element> LinkedDeque::~LinkedDeque() {
    //TODO
}
//Retorna el nombre d'elements que conté.
template <class Element> int LinkedDeque::size() const{
    return this->num_elements; 
}
//Retorna true si no hi ha cap element.
template <class Element> bool LinkedDeque::isEmpty() const{
    return (this->num_elements==0); 
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

