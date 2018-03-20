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

template <class Element> class LinkedDeque {
    public:
        LinkedDeque();
        ~LinkedDeque();
        LinkedDeque(const LinkedDeque<Element>& deque); bool isEmpty()const;
        void insertFront(const Element & element); void insertRear(const Element & element);
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

#endif /* LINKEDDEQUE_H */

