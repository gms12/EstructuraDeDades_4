/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeTree.h
 * Author: mpedembe7.alumnes
 *
 * Created on 17 / d’abril / 2018, 08:33
 */

#ifndef NODETREE_H
#define NODETREE_H

#ifdef __cplusplus

#endif


template <class Type> class NodeTree {
    public:
        NodeTree(const Type& data);
        NodeTree(const NodeTree& orig);
        virtual ~NodeTree(); // destructor
        /*Consultors*/
        NodeTree<Type>* getright() const;
        NodeTree<Type>* getleft() const;
        NodeTree<Type>* getparent() const;
        bool hasRight() const;
        bool hasLeft() const;
        bool isRoot() const;
        bool isExternal() const;
        const Type& getElement() const;
        int getHeight() const;
        void setHeight(int h);
        /*Modificadors*/
        void setData(const Type& data);
        void setRight(NodeTree<Type>* newRight);
        void setLeft(NodeTree<Type>* newLeft);
        void setParent(NodeTree<Type>* newParent);
    private:
        NodeTree<Type>* pParent;
        NodeTree<Type>* pLeft;
        NodeTree<Type>* pRight;
        Type data;
        int height;
};

#ifdef __cplusplus

#endif

#endif /* NODETREE_H */

