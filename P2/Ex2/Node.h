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
//Constructor per defecte. Inicialitza els punters i element a null.
template <class Element> Node<Element>::Node(){
    this->next=nullptr;
    this->previous=nullptr;
    this->element=NULL;
}
//Constructor amb pas d'element. Punters a null.
template <class Element> Node<Element>::Node(const Element e){
    this->next=nullptr;
    this->previous=nullptr;
    this->element=e;
}
//Destructor del Node. Eliminem l'element i els punters ara apunten a null.
template <class Element> Node<Element>::~Node(){
    this->next=nullptr;
    this->previous=nullptr;
    delete this->element;
}
//Aquest mètode retorna l'adreça de l'element que conté el Node.
template <class Element> Element& Node<Element>::getElement() const{
    return &(this->element);
}
//Aquest mètode retorna l'adreça del Node al qual apunta el punter next.
template <class Element> Node* Node<Element>::getNext() const{
    return this->next;
}
//Aquest mètode assigna el Node al qual apunta el punter next.
template <class Element> void Node<Element>::setNext(const Node* n){
    this->next=n;
}
//Aquest mètode retorna l'adreça del Node al qual apunta el punter previous.
template <class Element> Node* Node<Element>::getPrevious() const{
    return this->previous;
}
//Aquest mètode assigna el Node al qual apunta el punter previous.
template <class Element> void Node<Element>::setPrevious(const Node* n){
    this->previous=n;
}


#ifdef __cplusplus
}
#endif

#endif /* NODE_H */

