/*
 * TAD NodeTree, que farà de suport al TAD MinHeap.
 */

/* 
 * File:   NodeHeap.h
 * Author: Gabriel Marín i Martí Pedemonte
 *
 * Created on 1 / de maig / 2018, 08:33
 */

#ifndef NODEHEAP_H
#define NODEHEAP_H

#include <cstdlib>
#include <stdexcept>
#include <iostream>

using namespace std;

#ifdef __cplusplus

#endif


template <class Type> class NodeHeap {
    public:
        //Constructors
        NodeHeap(const Type& data, int key);
        NodeHeap(const NodeHeap& orig);
        //Destructor
        virtual ~NodeHeap();
        //Consultors
        NodeHeap<Type>* getRight() const;
        NodeHeap<Type>* getLeft() const;
        NodeHeap<Type>* getParent() const;
        bool hasRight() const;
        bool hasLeft() const;
        bool isRoot() const;
        bool isExternal() const;
        const Type& getValue() const;
        const int getKey() const;
        int getHeight() const;
        //Modificadors
        void setHeight(int h);
        void setValue(const Type& data);
        void setKey(int newKey);
        void setRight(NodeHeap<Type>* newRight);
        void setLeft(NodeHeap<Type>* newLeft);
        void setParent(NodeHeap<Type>* newParent);
    private:
        //Atributs
        NodeHeap<Type>* pParent;
        NodeHeap<Type>* pLeft;
        NodeHeap<Type>* pRight;
        Type data;
        int key;
        int height;
};

//Constructor amb pas d'element. Inicialitza els punters a null i l'element donat.
template <class Type> NodeHeap<Type>::NodeHeap(const Type& dataIn, int key){
    this->pParent = nullptr;
    this->pLeft = nullptr;
    this->pRight = nullptr;
    this->data = dataIn;
    this->key = key;
    this->height = 0;
}

//Constructor amb còpia d'un NodeTree.
template <class Type> NodeHeap<Type>::NodeHeap(const NodeHeap& orig){
    this->pParent = orig.getParent();
    this->pLeft = orig.getLeft();
    this->pRight = orig.getRight();
    this->data = orig.getValue();
    this->key = orig.getKey();
    this->height = orig.getHeight();
}

//Destructor del NodeTree. Els punters ara apunten a null, no cal eliminar data.
template <class Type> NodeHeap<Type>::~NodeHeap(){
    this->pParent = nullptr;
    this->pLeft = nullptr;
    this->pRight = nullptr;
    this->height = 0;
}

//Getter del NodeTree fill dret. Retorna punter a NodeTree.
template <class Type> NodeHeap<Type>* NodeHeap<Type>:: getRight() const{
    return this->pRight;
}

//Getter del NodeTree fill esquerre. Retorna punter a NodeTree.
template <class Type> NodeHeap<Type>* NodeHeap<Type>:: getLeft() const{
    return this->pLeft;
}

//Getter del NodeTree pare. Retorna punter a NodeTree.
template <class Type> NodeHeap<Type>* NodeHeap<Type>:: getParent() const{
    return this->pParent;
}

//Retorna true si té un fill dret, false en cas contrari.
template <class Type> bool NodeHeap<Type>:: hasRight() const{
    return !(this->pRight == nullptr);
} 

//Retorna true si té un fill esquerre, false en cas contrari.
template <class Type> bool NodeHeap<Type>:: hasLeft() const{
    return !(this->pLeft == nullptr);
}

//Retorna true si és arrel, false en cas contrari.
template <class Type> bool NodeHeap<Type>:: isRoot() const{
    return (this->pParent == nullptr);
}

//Retorna true si és fulla, false en cas contrari.
template <class Type> bool NodeHeap<Type>:: isExternal() const{
    return !(this->hasRight() || this->hasLeft());
}

//Retorna l'element que conté el NodeTree.
template <class Type> const Type& NodeHeap<Type>:: getValue() const{
    //const Type &e = this->data;
    //return e;
    return this->data;
}

//Retorna la clau de l'element que conté el NodeTree.
template <class Type> const int NodeHeap<Type>:: getKey() const{
    //const Type &e = this->data;
    //return e;
    return this->key;
}

//Retorna l'alçada del NodeTree.
template <class Type> int NodeHeap<Type>:: getHeight() const{
    return this->height;
}

//Assigna l'alçada del NodeTree.
template <class Type> void NodeHeap<Type>:: setHeight(int h){
    this->height = h;
}

//Assigna la dada del NodeTree.
template <class Type> void NodeHeap<Type>:: setValue(const Type& dataIn){
    this->data = dataIn;
}

//Assigna la id del NodeTree.
template <class Type> void NodeHeap<Type>:: setKey(int newKey){
    this->key = newKey;
}

//Assigna el fill dret.
template <class Type> void NodeHeap<Type>:: setRight(NodeHeap<Type>* newRight){
    this->pRight = newRight;
}

//Assigna el fill esquerre.
template <class Type> void NodeHeap<Type>:: setLeft(NodeHeap<Type>* newLeft){
    this->pLeft = newLeft;
}

//Assigna el pare.
template <class Type> void NodeHeap<Type>:: setParent(NodeHeap<Type>* newParent){
    this->pParent = newParent;
}

#ifdef __cplusplus

#endif

#endif /* NODEHEAP_H */

