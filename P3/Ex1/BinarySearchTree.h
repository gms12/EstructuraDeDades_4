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
template <class Type> virtual BinarySearchTree<Type>::~BinarySearchTree(){
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
    //TODO
    //...
}

//Mostra el contingut de l'arbre en recorregut inordre.
template <class Type> void BinarySearchTree<Type>::printInorder() const{
    this->printInorder(this->pRoot);
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
    //TODO
    //...
}

//Destrueix un arbre donada la seva arrel.
template <class Type> void BinarySearchTree<Type>::postDelete(NodeTree<Type>* p){
    //TODO
    //...
}

//Retorna el nombre de NodeTrees que hi ha en un arbre donada la seva arrel.
template <class Type> int BinarySearchTree<Type>::size(NodeTree<Type>* p) const{
    //TODO
    //...
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
    //TODO
    //...
}

//Retorna un enter amb l'alçada d'un arbre, donada la seva arrel.
template <class Type> int BinarySearchTree<Type>::getHeight(NodeTree<Type>* p){
    //TODO
    //...
}

#ifdef __cplusplus

#endif

#endif /* BINARYSEARCHTREE_H */

