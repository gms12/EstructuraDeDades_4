/*
 * TAD BinarySearchTree, utilitzant NodeTree.
 */

/* 
 * File:   BinarySearchTree.h
 * Author: Gabriel Marín i Martí Pedemonte
 *
 * Created on 17 / d’abril / 2018, 08:33
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <math.h>
#include "NodeTree.h"


#ifdef __cplusplus

#endif


template <class Type> class BinarySearchTree{
    public:
        //Constructors
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree& orig);
        //Destructor
        virtual ~BinarySearchTree();
        //Consultors
        int size() const;
        bool isEmpty() const;
        NodeTree<Type>* root();
        bool search(const Type& element);
        void printInorder() const;
        void printPreorder() const;
        void printPostorder() const;
        int getHeight();
        //Modificadors
        void insert(const Type& element);
    private:
        //Mètodes privats interns
        void postDelete(NodeTree<Type>* p);
        int size(NodeTree<Type>* p) const;
        void printPreorder(NodeTree<Type>* p) const;
        void printPostorder(NodeTree<Type>* p) const;
        void printInorder(NodeTree<Type>* p) const;
        int getHeight(NodeTree<Type>* p);
        void insert(NodeTree<Type>* p,const Type& element); //nou metode
        NodeTree<Type>* search(NodeTree<Type>* p,const Type& element);//nou metode
        //Atributs
        NodeTree<Type>* pRoot;
};

//Constructor per defecte. Punter arrel a null.
template <class Type> BinarySearchTree<Type>::BinarySearchTree(){
    this->pRoot = nullptr;
}

//Constructor còpia.
template <class Type> BinarySearchTree<Type>::BinarySearchTree(const BinarySearchTree& orig){
    //TODO
    //...
}

//Destructor.
template <class Type> /*virtual*/ BinarySearchTree<Type>::~BinarySearchTree(){
    this->postDelete(this->pRoot);
}

//Retorna el nombre de NodeTrees que hi ha a l'arbre.
template <class Type> int BinarySearchTree<Type>::size() const{
    this->size(this->pRoot);
}

//Retorna true si l'arbre està buit, false en cas contrari.
template <class Type> bool BinarySearchTree<Type>::isEmpty() const{
    return (this->pRoot == nullptr);
}

//Retorna l'adreça de l'arrel.
template <class Type> NodeTree<Type>* BinarySearchTree<Type>::root(){
    return this->pRoot;
}

//Cerca un element. Retorna true si el troba, false en cas contrari.
template <class Type> bool BinarySearchTree<Type>::search(const Type& element) {
    //si el node que retorna search es null, retornem false
    return this->search(pRoot,element)!=nullptr;
}
//Cerca un element a partir d'un node. Quan el troba retorna el node.
template <class Type> NodeTree<Type>* BinarySearchTree<Type>::search(NodeTree<Type>* p,const Type& element) {
    //si el node es null o el seu valor es el que busquem, el retornem
    if(p==nullptr || p->getData()==element)return p;
    //si el seu valor es mes gran, busquem al fill de l'esquerra
    else if(p->getData()>element)return search(p->getLeft(),element);
    //si no, com tindra un valor inferior, busquem al fill de la dreta
    else return search(p->getRight(),element);
}

//Mostra el contingut de l'arbre en recorregut inordre.
template <class Type> void BinarySearchTree<Type>::printInorder() const{
    cout<<"Inordre ={ ";
    this->printInorder(this->pRoot);
    cout<<"}";
    return; 
}

//Mostra el contingut de l'arbre en recorregut preordre.
template <class Type> void BinarySearchTree<Type>::printPreorder() const{
    this->printPreorder(this->pRoot);
}

//Mostra el contingut de l'arbre en recorregut postordre.
template <class Type> void BinarySearchTree<Type>::printPostorder() const{
    this->printPostorder(this->pRoot);
}

//Retorna un enter amb l'alçada de l'arbre.
template <class Type> int BinarySearchTree<Type>::getHeight(){
    this->getHeight(this->pRoot);
}

//Afegeix un nou NodeTree a l'arbre binari.
template <class Type> void BinarySearchTree<Type>::insert(const Type& element){
    if(this->isEmpty()){//comprovem si l'arbre esta buit
        this->pRoot=new NodeTree<Type>(element);
    }
    else this->insert(pRoot,element);//si no esta buit cridem el metode auxiliar
    cout<<"S'insereix a l'arbre l'element "<<element<<endl;
}
//Metode auxiliar a insert. Se li passa també un node, per a poder ser recursiu
template <class Type> void BinarySearchTree<Type>::insert(NodeTree<Type>* p, const Type& element){
    if(p->getData()>element){//si el valor es inferior, anira a l'esq
        if(!p->hasLeft()){
            p->setLeft(new NodeTree<Type>(element));
            
            
        }//si no te fill esq, l'afegim. Si no, cridem el metode pel fill de lesq
        else this->insert(p->getLeft(),element);
    }
    else{//si es superior anira a la dreta
       if(!p->hasRight()){//Igual que abans pero per l'altre costat
            p->setRight(new NodeTree<Type>(element));
            
        }
        else this->insert(p->getRight(),element);    
    }
}

//Destrueix un subarbre donada la seva arrel.
template <class Type> void BinarySearchTree<Type>::postDelete(NodeTree<Type>* p){
    //TODO
    //...
}

//Retorna el nombre de NodeTrees que hi ha en un subarbre donada la seva arrel.
template <class Type> int BinarySearchTree<Type>::size(NodeTree<Type>* p) const{
    //si el Node p es nul, retornem 0
    if(p==nullptr)return 0;
    //altrament, sabem que n'hi ha un i mirem els seus fills
    else return 1+size(p->getLeft())+size(p->getRight());
}

//Mostra el contingut d'un arbre en recorregut preordre, donada la seva arrel.
template <class Type> void BinarySearchTree<Type>::printPreorder(NodeTree<Type>* p) const{
    //TODO
    //...
}

//Mostra el contingut d'un arbre en recorregut postordre, donada la seva arrel.
template <class Type> void BinarySearchTree<Type>::printPostorder(NodeTree<Type>* p) const{
    //TODO
    //...
}

//Mostra el contingut d'un arbre en recorregut inordre, donada la seva arrel.
template <class Type> void BinarySearchTree<Type>::printInorder(NodeTree<Type>* p) const{
    if(p!=nullptr){
        //primer cridem el subarbre de l'esquerra
        this->printInorder(p->getLeft());
        //despres imprimim el seu element
        cout<<p->getData()<<" ";
        //per ultim cridem al subarbre de la dreta
        this->printInorder(p->getRight());
    }
      
}

//Retorna un enter amb l'alçada d'un arbre, donada la seva arrel.
template <class Type> int BinarySearchTree<Type>::getHeight(NodeTree<Type>* p){
    //si el Node p es nul, retornem -1. L'alçada d'una fulla serà 0
    if(p==nullptr)return -1;
    //altrament, sabem que n'hi ha un i mirem els seus fills
    else return 1+max(getHeight(p->getLeft()),getHeight(p->getRight()));
}

#ifdef __cplusplus

#endif

#endif /* BINARYSEARCHTREE_H */

