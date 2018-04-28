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
        BinarySearchTree();//TEST: OK
        BinarySearchTree(const BinarySearchTree& orig);//TEST: OK
        //Destructor
        virtual ~BinarySearchTree();//TEST: OK
        //Consultors
        int size() const;//TEST: OK
        bool isEmpty() const;//TEST: OK
        NodeTree<Type>* root() const;//TEST: OK
        NodeTree<Type>* search(int key);//TEST: OK
        void printInorder();//TEST: OK
        void printPreorder() const;//TEST: OK
        void printPostorder() const;//TEST: OK
        int getHeight();//TEST: OK
        int getCounter() const;//TEST: OK
        //Modificadors
        void insert(const Type& element, int key);//TEST: OK
        void setCounter(int c);
        //Mirall
        BinarySearchTree<Type>* mirror();//TEST: OK
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
template <class Type> BinarySearchTree<Type>::BinarySearchTree(){
    this->pRoot = nullptr;
    this->counter = 0;
    cout << "Arbre creat" << endl;
}

//Constructor còpia.
template <class Type> BinarySearchTree<Type>::BinarySearchTree(const BinarySearchTree& orig){
    this->pRoot = constructor_copia(orig.root());
    this->counter = orig.getCounter();
    cout << "Arbre creat" << endl;
}
//Metode auxuliar per al constructor. Recorrem en preordre i anem copiant node a node
template <class Type> NodeTree<Type>* BinarySearchTree<Type>::constructor_copia(NodeTree<Type>* from){
    if(from==nullptr)return nullptr;//si l'arbre donat és null fem el nostre null
    else{
        NodeTree<Type>* newNode = new NodeTree<Type>(*from);//copiem el node
        newNode->setLeft(constructor_copia(from->getLeft()));//cridem per copiar el node de l'esq
        newNode->setRight(constructor_copia(from->getRight()));//cridem per copiar el node de la dreta    
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
template <class Type> NodeTree<Type>* BinarySearchTree<Type>::root() const{
    return this->pRoot;
}

//Cerca un element. Retorna true si el troba, false en cas contrari.
template <class Type> NodeTree<Type>* BinarySearchTree<Type>::search(int key) {
    return this->search(pRoot,key);
}

//Cerca un element a partir d'un node. Quan el troba retorna el node.
template <class Type> NodeTree<Type>* BinarySearchTree<Type>::search(NodeTree<Type>* p, int key) {
    //si el node es null o el seu valor es el que busquem, el retornem
    if(p==nullptr || p->getKey()==key)return p;
    //si el seu valor es mes gran, busquem al fill de l'esquerra
    else if(p->getKey()>key && p->hasLeft()){
        return search(p->getLeft(),key);
    }
    //si no, com tindra un valor inferior, busquem al fill de la dreta
    else if(p->hasRight()){
        return search(p->getRight(),key);
    }
    return nullptr;//Si no ha estat agafat en un dels dos ifs vol dir que no existeix l'element
}

//Mostra el contingut de l'arbre en recorregut inordre.
template <class Type> void BinarySearchTree<Type>::printInorder() {
    cout<<"Inordre = {"<<endl;
    this->printInorder(this->pRoot);
    cout<<"}"<<endl;
    this->counter = 0;
    return; 
}

//Mostra el contingut de l'arbre en recorregut preordre.
template <class Type> void BinarySearchTree<Type>::printPreorder() const{
    cout<<"Preordre = {"<<endl;
    this->printPreorder(this->pRoot);
    cout<<"}"<<endl;
}

//Mostra el contingut de l'arbre en recorregut postordre.
template <class Type> void BinarySearchTree<Type>::printPostorder() const{
    cout<<"Postordre = {"<<endl;
    this->printPostorder(this->pRoot);
    cout<<"}"<<endl;
}

//Retorna un enter amb l'alçada de l'arbre.
template <class Type> int BinarySearchTree<Type>::getHeight(){
    return this->getHeight(this->pRoot);
}

//Retorna un enter el comptador
template <class Type> int BinarySearchTree<Type>::getCounter() const{
    return this->counter;
}

//Afegeix un nou NodeTree a l'arbre binari.
template <class Type> void BinarySearchTree<Type>::insert(const Type& element, int key){
    if(this->isEmpty()){//comprovem si l'arbre esta buit
        this->pRoot=new NodeTree<Type>(element, key);
    }
    else this->insert(pRoot,element, key);//si no esta buit cridem el metode auxiliar
    cout<<"S'insereix a l'arbre l'element "<<element.toString()<<endl;
}

//Retorna un enter el comptador
template <class Type> void BinarySearchTree<Type>::setCounter(int c){
    this->counter = c;
}

//Metode auxiliar a insert. Se li passa també un node, per a poder ser recursiu
template <class Type> void BinarySearchTree<Type>::insert(NodeTree<Type>* p, const Type& element, int key){
    if(p->getKey()>key){//si el valor es inferior, anira a l'esq
        if(!p->hasLeft()){
            p->setLeft(new NodeTree<Type>(element, key));
        }//si no te fill esq, l'afegim. Si no, cridem el metode pel fill de lesq
        else this->insert(p->getLeft(),element, key);
    }
    else{//si es superior anira a la dreta
       if(!p->hasRight()){//Igual que abans pero per l'altre costat
            p->setRight(new NodeTree<Type>(element, key));
        }
       else this->insert(p->getRight(),element, key);    
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
        cout<<p->getValue().toString()<<endl;
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
        cout<<p->getValue().toString()<<endl;       
    }
}

//Mostra el contingut d'un arbre en recorregut inordre, donada la seva arrel.
template <class Type> void BinarySearchTree<Type>::printInorder(NodeTree<Type>* p) {
    if(this->counter < 0) return;
    if(p!=nullptr){
        //primer cridem el subarbre de l'esquerra
        if(p->hasLeft()) this->printInorder(p->getLeft());
        //despres imprimim el seu element
        if(this->counter < 0) return;
        cout<<p->getValue().toString()<<endl;
        this->counter++;
        if(counter >= 39){
            cout<<endl<<"Do you want to continue? (Y/N)";
            string resposta;
            cin>>resposta;
            while(resposta != "Y" && resposta != "N" && resposta != "y" && resposta != "n"){
                cout<<"It's not that hard, dude. Do you want to continue? (Y/N)";
                cin>>resposta;
            }
            if(resposta == "Y" || resposta == "y") this->counter = 0;
            else {this->counter = -10; return;}
            cout<<endl;
        }
        if(this->counter < 0) return;
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
        NodeTree<Type>* to = new NodeTree<Type>(*from, from->getKey());//copiem el node
        to->setLeft(constructor_mirall(from->getRight()));//cridem per copiar el node de la dreta a l'esq
        to->setRight(constructor_mirall(from->getLeft()));//cridem per copiar el node de l'esq a la dreta
        return to;//retornem el node
    }
}

#ifdef __cplusplus

#endif

#endif /* BINARYSEARCHTREE_H */

