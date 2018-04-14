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
#include <stdexcept>
#include <iostream>
#include "Node.h"
using namespace std;
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
    Node<Element> *f1=new Node<Element>();
    Node<Element> *f2=new Node<Element>();
    this->_front=f1;
    this->_rear=f2;
    f1->setNext(this->_rear);
    f2->setPrevious(this->_front);
}

template <class Element> LinkedDeque::LinkedDeque(LinkedDeque<Element>& deque) {
    Node<Element> *f1=new Node<Element>();//sentinella inicial
    Node<Element> *f2=new Node<Element>();//sentinella final
    this->_front=f1;
    this->_rear=f2; 
    f1->setNext(this->_rear);
    f2->setPrevious(this->_front);//aixo es el mateix pels dos constructors
    Node<Element> *aux;//aux recorrera el deque.
    aux=deque->_front;//fem que aux apunti al sentinella frontal de deque
    for(int i=0;i<deque->num_elements;i++){//recorrem en funcio del size de deque
        aux=aux->getNext();//apuntem al seguent node
        this->getRear(aux->getElement());//anem posat els nodes pel darrera, aixi el primer que posem sempre estarà davant
    }
    delete aux; //eliminem aux, tot i que no se si es necessari
}

template <class Element> LinkedDeque::~LinkedDeque() {
    while(!this->isEmpty()){
        //mentres la cua no sigui buida, li anem treient l'element de davant
        this->deleteFront();
    }
    //finalment eliminem els sentinelles
    delete this->_front;
    delete this->_rear;
    this->_front=nullptr;
    this->_rear=nullptr;
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
    Node<Element> *_nou=new Node<Element>(element);
    this->_front->getNext()->setPrevious(_nou);
    _nou->setNext(this->_front->getNext());
    _nou->setPrevious(this->_front);
    this->_front->setNext(_nou); 
}
template <class Element> void LinkedDeque::insertRear(const Element& element){
    Node<Element> *_nou=new Node<Element>(element);
    this->_rear->getPrevious()->setNext(_nou);
    _nou->setPrevious(this->_rear->getPrevious());
    _nou->setNext(this->_rear);
    this->_rear->setPrevious(_nou);
}
//Si la llista no es buida, eliminem el node que apunta el front.
template <class Element> void LinkedDeque::deleteFront(){
    if(this->isEmpty())throw invalid_argument("La cua és buida.");
    else{
        Node<Element> *_aux; //node auxiliar que apuntarà al node que volem eliminar
        _aux=this->_front->getNext(); //assigmen el node auxiliar
        _aux->getNext()->setPrevious(this->_front); //movem la "fletxa" que apunta el node 2 al node 1
        this->_front->setNext(_aux->getNext()); //movem la "fletxa" del sentinella que apuntara al node 2 ara
        delete _aux; //eliminem el node
    }
}
//Si la llista no es buida, eliminem el node que apunta el rear.
template <class Element> void LinkedDeque::deleteRear(){
    if(this->isEmpty())throw invalid_argument("La cua és buida.");
    else{
        Node<Element> *_aux; //node auxiliar que apuntarà al node que volem eliminar
        _aux=this->_rear->getPrevious(); //assigmen el node auxiliar
        _aux->getPrevious()->setNext(this->_rear);//movem la "fletxa" que apunta el node n al node n-1
        this->_rear->setPrevious(_aux->getPrevious()); //movem la "fletxa" del sentinella que apuntara al node n-1 ara
        delete _aux; //eliminem el node
    }
}
template <class Element> void LinkedDeque::print(){
    if(this->isEmpty())throw invalid_argument("La cua és buida.");
    else{
        Node<Element> *_aux; //node auxiliar que recorrera la cua
        _aux=this->_front;//aux apunta al primer node sentinella
        while(_aux->getNext()!=this->_rear){ //mentres el seguent no sigui l'ultim sentinella seguim
            _aux=_aux->getNext();//assignem al seguent node
            cout<<_aux->getElement()<<endl;//imprimim l'element
 
        }
    }
}
//Comprovem que la cua no sigui buida i si no es dona el cas retornem l'element
//del node on apunta el front. Recordem que hi ha el sentinella.
template <class Element> const Element& LinkedDeque::getFront() const{
    if(this->isEmpty())throw invalid_argument("La cua és buida.");
    else{
        return this->_front->getNext()->getElement();
    }
}
//Comprovem que la cua no sigui buida i si no es dona el cas retornem l'element
//del node on apunta el rear. Recordem que hi ha el sentinella.
template <class Element> const Element& LinkedDeque::getRear() const{
    if(this->isEmpty())throw invalid_argument("La cua és buida.");
    else{
        return this->_rear->getPrevious()->getElement();
    }
}

#endif /* LINKEDDEQUE_H */

