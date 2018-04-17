/*
 * TAD NodeTree, que farà de suport al TAD BinarySearchTree.
 */

/* 
 * File:   NodeTree.h
 * Author: Gabriel Marín i Martí Pedemonte
 *
 * Created on 17 / d’abril / 2018, 08:33
 */

#ifndef NODETREE_H
#define NODETREE_H

#ifdef __cplusplus

#endif


template <class Type> class NodeTree {
    public:
        //Constructors
        NodeTree(const Type& data);
        NodeTree(const NodeTree& orig);
        //Destructor
        virtual ~NodeTree();
        //Consultors
        NodeTree<Type>* getRight() const;
        NodeTree<Type>* getLeft() const;
        NodeTree<Type>* getParent() const;
        bool hasRight() const;
        bool hasLeft() const;
        bool isRoot() const;
        bool isExternal() const;
        const Type& getElement() const;
        int getHeight() const;
        //Modificadors
        void setHeight(int h);
        void setData(const Type& data);
        void setRight(NodeTree<Type>* newRight);
        void setLeft(NodeTree<Type>* newLeft);
        void setParent(NodeTree<Type>* newParent);
    private:
        //Atributs
        NodeTree<Type>* pParent;
        NodeTree<Type>* pLeft;
        NodeTree<Type>* pRight;
        Type data;
        int height;
};

//Constructor amb pas d'element. Inicialitza els punters a null i l'element donat.
template <class Type> NodeTree<Type>::NodeTree(const Type& dataIn){
    this->pParent = nullptr;
    this->pLeft = nullptr;
    this->pRight = nullptr;
    this->data = dataIn;
    this->height = 0;
}

//Constructor amb còpia d'un NodeTree.
template <class Type> NodeTree<Type>::NodeTree(const NodeTree& orig){
    this->pParent = orig->getParent();
    this->pLeft = orig->getLeft();
    this->pRight = orig->getRight();
    this->data = orig->getElement();
    this->height = orig->getHeight();
}

//Destructor del NodeTree. Els punters ara apunten a null, no cal eliminar data.
template <class Type> NodeTree<Type>::~NodeTree(){
    this->pParent = nullptr;
    this->pLeft = nullptr;
    this->pRight = nullptr;
    this->height = 0;
}

//Getter del NodeTree fill dret. Retorna punter a NodeTree.
template <class Type> NodeTree<Type>* NodeTree<Type>:: getRight() const{
    return this->pRight;
}

//Getter del NodeTree fill esquerre. Retorna punter a NodeTree.
template <class Type> NodeTree<Type>* NodeTree<Type>:: getLeft() const{
    return this->pLeft;
}

//Getter del NodeTree pare. Retorna punter a NodeTree.
template <class Type> NodeTree<Type>* NodeTree<Type>:: getParent() const{
    return this->pParent;
}

//Retorna true si té un fill dret, false en cas contrari.
template <class Type> bool NodeTree<Type>:: hasRight() const{
    return !(this->pRight == nullptr);
} 

//Retorna true si té un fill esquerre, false en cas contrari.
template <class Type> bool NodeTree<Type>:: hasLeft() const{
    return !(this->pLeft == nullptr);
}

//Retorna true si és arrel, false en cas contrari.
template <class Type> bool NodeTree<Type>:: isRoot() const{
    return (this->pParent == nullptr);
}

//Retorna true si és fulla, false en cas contrari.
template <class Type> bool NodeTree<Type>:: isExternal() const{
    return !(this->hasRight() || this->hasLeft());
}

//Retorna l'element que conté el NodeTree.
template <class Type> const Type& NodeTree<Type>:: getElement() const{
    //const Type &e = this->data;
    //return e;
    return this->data;
}

//Retorna l'alçada del NodeTree.
template <class Type> int NodeTree<Type>:: getHeight() const{
    return this->height;
}

//Assigna l'alçada del NodeTree.
template <class Type> void NodeTree<Type>:: setHeight(int h){
    this->height = h;
}

//Assigna la dada del NodeTree.
template <class Type> void NodeTree<Type>:: setData(const Type& dataIn){
    this->data = dataIn;
}

//Assigna el fill dret.
template <class Type> void NodeTree<Type>:: setRight(NodeTree<Type>* newRight){
    this->pRight = newRight;
}

//Assigna el fill esquerre.
template <class Type> void NodeTree<Type>:: setLeft(NodeTree<Type>* newLeft){
    this->pLeft = newLeft;
}

//Assigna el pare.
template <class Type> void NodeTree<Type>:: setParent(NodeTree<Type>* newParent){
    this->pParent = newParent;
}

#ifdef __cplusplus

#endif

#endif /* NODETREE_H */

