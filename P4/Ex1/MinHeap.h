/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MinHeap.h
 * Author: Gabriel
 *
 * Created on 20 de mayo de 2018, 15:43
 */

#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include <math.h>
#include <vector>
#include "NodeHeap.h"
using namespace std;
#ifdef __cplusplus
#endif

template <class Type> class MinHeap{
        public:
        //Constructors
        MinHeap();//TEST: 
        //Destructor
        virtual ~MinHeap();//TEST: 
        //Consultors
        int size() const;//TEST: 
        bool isEmpty() const;//TEST: 
        void print();//TEST: 
        int min() const;//TEST
        Type minValue() const;//TEST
        //Modificadors
        void insert(const Type& element, int key);//TEST: 
    private:
        //Metodes privats
        void bubbleUp(int index);
        //Atributs
        vector<NodeHeap*> minHeap;
    };
    
//Constructor per defecte. Punter arrel a null.
template <class Type> MinHeap<Type>::MinHeap(){
    vector<NodeHeap*> mH;
    this->minHeap=mH;
    cout << "MinHeap creat" << endl;
}
//Destructor
template<class Type> MinHeap<Type>::~MinHeap(){
    vector<NodeHeap *>::iterator it;
    for(it=this->minHeap.begin();it!=this->minHeap.end();it++){
        delete *it;
    }
    this->minHeap.clear();
    vector<NodeHeap*>().swap(this->minHeap);
    cout<<"MinHeap eliminat."<<endl;
}
//Size
template<class Type> int MinHeap<Type>::size() const{
    return this->minHeap.size();
}
//isEmpty
template<class Type> void MinHeap<Type>::isEmpty() const{
    return this->size();//si la mida es 0 retornara true, i si es meajor aleshores false
}
//Print


//Insert
template<class Type> void MinHeap<Type>::insert(const Type& element, int key){
    int index=this->size();
    int indexParent;
    NodeHeap* node=new NodeHeap(element,key);
    //connectem pare i fill
    //cas parell
    if(index%2==0){
        indexParent=(index-2)/2;
    }
    //cas senar
    else{
        indexParent=(index-1)/2;
    }
    this->minHeap[indexParent]->setRight(node);
    node->setParent(this->minHeap[indexParent]); 
    this->minHeap.push_back(node);
    this->bubbleUp(index);
}
//Bubble up. Anira pujant i comprovant que tot està bé. Si no canviarà els nodes que toquin
template<class Type> void MinHeap<Type>::bubbleUp(int index){
    if(index==0)return;
    int indexParent;
    if(index%2==0){
        indexParent=(index-2)/2;
    }
    else{
        indexParent=(index-1)/2;
    }
    if(minHeap[indexParent]->getKey()>minHeap[index]->getKey()){
        //Intercanviem els nodes. Primer movem els punters
        NodeHeap* tmp=new NodeHeap(minHeap[index]);
        NodeHeap* aux;
        minHeap[index]->setParent(minHeap[indexParent]->getParent());
        minHeap[index]->setLeft(minHeap[indexParent]->getLeft());
        minHeap[index]->setRight(minHeap[indexParent]->getRight());
        minHeap[indexParent]->setParent(minHeap[index]);
        minHeap[indexParent]->setLeft(tmp->getLeft());
        minHeap[indexParent]->setRight(tmp->getRight());
        delete(tmp);
        aux=minHeap[index];
        minHeap[index]=minHeap[indexParent];
        minHeap[indexParent]=aux;
        this->bubbleUp(indexParent);
    }
       
}

//MinKey
template<class Type> int MinHeap<Type>::min() const{
    if(size()>0){
        return this->minHeap[0]->getKey();
    }
    else{
        throw invalid_argument("El MinHeap és buit.");
    }
}

//MinValue
template<class Type> Type MinHeap<Type>::minValue() const{
    if(size()>0){
        return this->minHeap[0]->getValue();
    }
    else{
        throw invalid_argument("El MinHeap és buit.");
    }
}
#ifdef __cplusplus
#endif

#endif /* MINHEAP_H */

