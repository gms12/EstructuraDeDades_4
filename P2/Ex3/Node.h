/*
 * TAD Node, que farà de suport al TAD LinkedDeque.
 */

/* 
 * File:   Node.h
 * Author: Martí Pedemonte i Gabriel Marín
 *
 * Created on 20 / de març / 2018, 08:37
 */

#ifndef NODE_H
#define NODE_H

#ifdef __cplusplus
#endif

    
#include <stdexcept>
#include <iostream>
using namespace std;    
    
template <class Element> class Node{
    public:
        Node();
        Node(const Element &e);
        ~Node();
        const Element& getElement() ;
        Node<Element> * getNext() ;
        void setNext(Node<Element> *node);
        Node<Element> * getPrevious() ;
        void setPrevious(Node<Element> *node);        
        
    private:
        Element element;
        Node<Element> *next;
        Node<Element> *previous;
};
//Constructor per defecte. Inicialitza els punters i element a null.
template <class Element> Node<Element>::Node(){
    this->next=nullptr;
    this->previous=nullptr;
    Element *e = &(this->element);
    e = NULL;
}
//Constructor amb pas d'element. Punters a null.
template <class Element> Node<Element>::Node(const Element &e){
    this->next=nullptr;
    this->previous=nullptr;
    this->element=e;
}
//Destructor del Node. Eliminem l'element i els punters ara apunten a null.
template <class Element> Node<Element>::~Node(){
    this->next=nullptr;
    this->previous=nullptr;
    Element *e = &(this->element);
    delete e;
}
//Aquest mètode retorna l'adreça de l'element que conté el Node.
template <class Element> const Element& Node<Element>::getElement() {
    const Element &e = this->element;
    return e;
}
//Aquest mètode retorna l'adreça del Node al qual apunta el punter next.
template <class Element> Node<Element>* Node<Element>::getNext() {
    return this->next;
}
//Aquest mètode assigna el Node al qual apunta el punter next.
template <class Element> void Node<Element>::setNext(Node<Element> *n){
    this->next=n;
}
//Aquest mètode retorna l'adreça del Node al qual apunta el punter previous.
template <class Element> Node<Element>* Node<Element>::getPrevious() {
    return this->previous;
}
//Aquest mètode assigna el Node al qual apunta el punter previous.
template <class Element> void Node<Element>::setPrevious(Node<Element> *n){
    this->previous=n;
}


#ifdef __cplusplus

#endif

#endif /* NODE_H */

