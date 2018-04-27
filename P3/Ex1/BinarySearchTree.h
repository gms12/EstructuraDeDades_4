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
using namespace std;



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
        //Mirall
        BinarySearchTree<Type>* mirror();
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
        NodeTree<Type>* constructor_copia(NodeTree<Type>* from);//nou metode
        NodeTree<Type>* constructor_mirall(NodeTree<Type>* from);//nou metode
        //Atributs
        NodeTree<Type>* pRoot;
};

//Constructor per defecte. Punter arrel a null.
template <class Type> BinarySearchTree<Type>::BinarySearchTree(){
    this->pRoot = nullptr;
    cout << "Arbre creat" << endl;
}

//Constructor còpia.
template <class Type> BinarySearchTree<Type>::BinarySearchTree(const BinarySearchTree& orig){
    this->pRoot = constructor_copia(orig->root());
    cout << "Arbre creat" << endl;
}
//Metode auxuliar per al constructor. Recorrem en preordre i anem copiant node a node
template <class Type> NodeTree<Type>* BinarySearchTree<Type>::constructor_copia(NodeTree<Type>* from){
    if(from==nullptr)return nullptr;//si l'arbre donat és null fem el nostre null
    else{
        NodeTree<Type>* newNode = new NodeTree<Type>(*from);//copiem el node
        if(from->hasLeft()){
            newNode->setLeft(constructor_copia(from->getLeft()));//cridem per copiar el node de l'esq
        }
        if(from->hasRight()){
            newNode->setRight(constructor_copia(from->getRight()));//cridem per copiar el node de la dreta
        }        
        return newNode;//retornem el node
    }
}

//Destructor.
template <class Type> /*virtual*/ BinarySearchTree<Type>::~BinarySearchTree(){
    this->postDelete(this->pRoot);
    cout << "Arbre eliminat" << endl;
}

//Retorna el nombre de NodeTrees que hi ha a l'arbre.
template <class Type> int BinarySearchTree<Type>::size() const{
    return this->size(this->pRoot);
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
template <class Type> NodeTree<Type>* BinarySearchTree<Type>::search(NodeTree<Type>* p, const Type& element) {
    //si el node es null o el seu valor es el que busquem, el retornem
    if(p==nullptr || p->getData()==element)return p;
    //si el seu valor es mes gran, busquem al fill de l'esquerra
    else if(p->getData()>element && p->hasLeft()){
        return search(p->getLeft(),element);
    }
    //si no, com tindra un valor inferior, busquem al fill de la dreta
    else if(p->hasRight()){
        return search(p->getRight(),element);
    }
    return nullptr;//Si no ha estat agafat en un dels dos ifs vol dir que no existeix l'element
}

//Mostra el contingut de l'arbre en recorregut inordre.
template <class Type> void BinarySearchTree<Type>::printInorder() const{
    cout<<"Inordre ={ ";
    this->printInorder(this->pRoot);
    cout<<"}"<<endl;
    return; 
}

//Mostra el contingut de l'arbre en recorregut preordre.
template <class Type> void BinarySearchTree<Type>::printPreorder() const{
    cout<<"Preordre ={ ";
    this->printPreorder(this->pRoot);
    cout<<"}"<<endl;
}

//Mostra el contingut de l'arbre en recorregut postordre.
template <class Type> void BinarySearchTree<Type>::printPostorder() const{
    cout<<"Postordre ={ ";
    this->printPostorder(this->pRoot);
    cout<<"}"<<endl;
}

//Retorna un enter amb l'alçada de l'arbre.
template <class Type> int BinarySearchTree<Type>::getHeight(){
    return this->getHeight(this->pRoot);
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
    if(p!=nullptr){    
        //primer eliminem el subarbre de l'esquerra
        if(p->hasLeft()) this->postDelete(p->getLeft());
        //despres eliminem al subarbre de la dreta
        if(p->hasRight()) this->postDelete(p->getRight());
        //per ultim eliminem el node en questio
        delete p;
    }
}

//Retorna el nombre de NodeTrees que hi ha en un subarbre donada la seva arrel.
template <class Type> int BinarySearchTree<Type>::size(NodeTree<Type>* p) const{
    //si el Node p es nul, retornem 0
    if(p==nullptr) return 0;
    //altrament, sabem que n'hi ha un i mirem els seus fills
    else return 1 + size(p->getLeft()) + size(p->getRight());
}

//Mostra el contingut d'un arbre en recorregut preordre, donada la seva arrel.
template <class Type> void BinarySearchTree<Type>::printPreorder(NodeTree<Type>* p) const{
    if(p!=nullptr){
        //primer imprimim l'element del node
        cout<<p->getData()<<" ";
        //despres cridem el subarbre de l'esquerra
        if(p->hasLeft()) this->printPreorder(p->getLeft());
        //per ultim cridem al subarbre de la dreta
        if(p->hasRight()) this->printPreorder(p->getRight());
    }
}

//Mostra el contingut d'un arbre en recorregut postordre, donada la seva arrel.
template <class Type> void BinarySearchTree<Type>::printPostorder(NodeTree<Type>* p) const{
    if(p!=nullptr){    
        //primer cridem el subarbre de l'esquerra
        if(p->hasLeft()) this->printPostorder(p->getLeft());
        //despres cridem al subarbre de la dreta
        if(p->hasRight()) this->printPostorder(p->getRight());
        //per ultim imprimim l'element del node
        cout<<p->getData()<<" ";
    }
}

//Mostra el contingut d'un arbre en recorregut inordre, donada la seva arrel.
template <class Type> void BinarySearchTree<Type>::printInorder(NodeTree<Type>* p) const{
    if(p!=nullptr){
        //primer cridem el subarbre de l'esquerra
        if(p->hasLeft()) this->printInorder(p->getLeft());
        //despres imprimim el seu element
        cout<<p->getData()<<" ";
        //per ultim cridem al subarbre de la dreta
        if(p->hasRight()) this->printInorder(p->getRight());
    }
}

//Retorna un enter amb l'alçada d'un arbre, donada la seva arrel.
template <class Type> int BinarySearchTree<Type>::getHeight(NodeTree<Type>* p){
    //si el Node p es nul, retornem -1. L'alçada d'una fulla serà 0
    if(p==nullptr)return -1;
    //altrament, sabem que n'hi ha un i mirem els seus fills
    else return 1 + max(getHeight(p->getLeft()),getHeight(p->getRight()));
}

//Retorna un arbre que sera el mirall de l'actual
template <class Type> BinarySearchTree<Type>* BinarySearchTree<Type>::mirror(){
    BinarySearchTree<Type>* bst_mirror = new BinarySearchTree<Type>();
    bst_mirror->pRoot = this->constructor_mirall(this->pRoot);
    return bst_mirror;
}
//Metode auxuliar per a mirror. Recorrem en preordre i anem copiant node a node, pero el de l'esq anira a la dreta
template <class Type> NodeTree<Type>* BinarySearchTree<Type>::constructor_mirall(NodeTree<Type>* from){
    if(from==nullptr)return nullptr;//si el node es null fem el nostre null
    else{
        NodeTree<Type>* to = new NodeTree<Type>(*from);//copiem el node
        if(from->hasRight()) to->setLeft(constructor_mirall(from->getRight()));//cridem per copiar el node de la dreta a l'esq
        if(from->hasLeft()) to->setRight(constructor_mirall(from->getLeft()));//cridem per copiar el node de l'esq a la dreta
        return to;//retornem el node
    }
}

#ifdef __cplusplus

#endif

#endif /* BINARYSEARCHTREE_H */

