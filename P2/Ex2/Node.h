/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: mpedembe7.alumnes
 *
 * Created on 20 / de març / 2018, 08:37
 */

#ifndef NODE_H
#define NODE_H

#ifdef __cplusplus
extern "C" {
#endif

    
#include <stdexcept>
#include <iostream>
using namespace std;    
    
template <class Element> class Node{
    public:
        Node();
        ~Node();
        Node(const Element e);
        const Element& getElement() const;
        const Node* getNext() const;
        void setNext(Node* node);
        const Node* getPrevious() const;
        void setPrevious(Node* node);        
        
    private:
        Element element;
        Node* next;
        Node* previous;
};

template <class Element> Node<Element>::Node(){
    this->next=nullptr;
    this->previous=nullptr;
    this->element=NULL;
}

template <class Element> Node<Element>::Node(const Element e){
    this->next=nullptr;
    this->previous=nullptr;
    this->element=e;
}

template <class Element> Node<Element>::~Node(){
    this->next=nullptr;
    this->previous=nullptr;
    delete this->element;
}

template <class Element> Element& Node<Element>::getElement() const{
    return &(this->element);
}

template <class Element> Node* Node<Element>::getNext() const{
    return this->next;
}

template <class Element> void Node<Element>::setNext(const Node* n){
    this->next=n;
}

template <class Element> Node* Node<Element>::getPrevious() const{
    return this->previous;
}

template <class Element> void Node<Element>::setPrevious(const Node* n){
    this->previous=n;
}


#ifdef __cplusplus
}
#endif

#endif /* NODE_H */

