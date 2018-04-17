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
        /*Constructors i Destructors*/
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree& orig);
        virtual ~BinarySearchTree();
        /*Consultors*/
        int size() const;
        bool isEmpty() const;
        NodeTree<Type>* root();
        bool search(const Type& element);
        void printInorder() const;
        void printPreorder() const;
        void printPostorder() const;
        int getHeight();
        /*Modificadors*/
        void insert(const Type& element);
    private:
        void postDelete(NodeTree<Type>* p);
        int size(NodeTree<Type>* p) const;
        void printPreorder(NodeTree<Type>* p) const;
        void printPostorder(NodeTree<Type>* p) const;
        void printInorder(NodeTree<Type>* p) const;
        int getHeight(NodeTree<Type>* p);
        /*Atributs*/
        NodeTree<Type>* pRoot;
};

#ifdef __cplusplus

#endif

#endif /* BINARYSEARCHTREE_H */

