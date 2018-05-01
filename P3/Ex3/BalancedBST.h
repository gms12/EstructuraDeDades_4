/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BalancedBST.h
 * Author: Gabriel
 *
 * Created on 1 de mayo de 2018, 20:49
 */

#ifndef BALANCEDBST_H
#define BALANCEDBST_H

#include <iostream>
#include <math.h>
#include "NodeTree.h"
using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

    template <class Type> class BalancedBST{
        public:
        //Constructors
        BalancedBST();//TEST: 
        BalancedBST(const BalancedBST& orig);//TEST: 
        //Destructor
        virtual ~BalancedBST();//TEST: 
        //Consultors
        int size() const;//TEST: 
        bool isEmpty() const;//TEST: 
        NodeTree<Type>* root() const;//TEST: 
        NodeTree<Type>* search(int key);//TEST: 
        void printInorder();//TEST: 
        void printPreorder() const;//TEST: 
        void printPostorder() const;//TEST: 
        int getHeight();//TEST: 
        int getCounter() const;//TEST: 
        //Modificadors
        void insert(const Type& element, int key);//TEST: 
        void setCounter(int c);
        //Mirall
        BalancedBST<Type>* mirror();//TEST: 
    private:
        //Mètodes privats interns
        void postDelete(NodeTree<Type>* p);
        int size(NodeTree<Type>* p) const;
        void printPreorder(NodeTree<Type>* p) const;
        void printPostorder(NodeTree<Type>* p) const;
        void printInorder(NodeTree<Type>* p);
        int getHeight(NodeTree<Type>* p);
        void insert(NodeTree<Type>* p, const Type& element, int key); //nou metode
        NodeTree<Type>* search(NodeTree<Type>* p, int key);//nou metode
        NodeTree<Type>* constructor_copia(NodeTree<Type>* from);//nou metode
        NodeTree<Type>* constructor_mirall(NodeTree<Type>* from);//nou metode
        //Atributs
        NodeTree<Type>* pRoot;
        int counter;
    };

//Constructor per defecte. Punter arrel a null.
template <class Type> BalancedBST<Type>::BalancedBST(){
    this->pRoot = nullptr;
    this->counter = 0;
    cout << "Arbre creat" << endl;
}
//Constructor còpia.
template <class Type> BalancedBST<Type>::BalancedBST(const BalancedBST& orig){
    this->pRoot = constructor_copia(orig.root());
    this->counter = orig.getCounter();
    cout << "Arbre creat" << endl;
}
//Metode auxuliar per al constructor. Recorrem en preordre i anem copiant node a node
template <class Type> NodeTree<Type>* BalancedBST<Type>::constructor_copia(NodeTree<Type>* from){
    if(from==nullptr)return nullptr;//si l'arbre donat és null fem el nostre null
    else{
        NodeTree<Type>* newNode = new NodeTree<Type>(*from);//copiem el node
        newNode->setLeft(constructor_copia(from->getLeft()));//cridem per copiar el node de l'esq
        newNode->setRight(constructor_copia(from->getRight()));//cridem per copiar el node de la dreta    
        return newNode;//retornem el node
    }
}
//Destructor.
template <class Type> BalancedBST<Type>::~BalancedBST(){
    this->postDelete(this->pRoot);
    cout << "Arbre eliminat" << endl;
}

#ifdef __cplusplus
}
#endif

#endif /* BALANCEDBST_H */

