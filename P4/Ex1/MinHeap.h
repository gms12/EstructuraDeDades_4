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
        void insert(const Type& element);//TEST: 
    private:
        //Metodes privats
        void bubbleUp(int index);
        //Atributs
        vector<Type> minHeap;
    };
    
//Constructor per defecte. Punter arrel a null.
template <class Type> MinHeap<Type>::MinHeap(){
    vector<Type> mH;
    this->minHeap=mH;
    cout << "MinHeap creat" << endl;
}
//Destructor
template<class Type> MinHeap<Type>::~MinHeap(){
    vector<Type>::iterator it;
    for(it=this->minHeap.begin();it!=this->minHeap.end();it++){
        delete *it;
    }
    this->minHeap.clear();
    vector<Type>().swap(this->minHeap);
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
template<class Type> void MinHeap<Type>::insert(const Type& element){
    int index=this->size();
    int indexParent;
    //connectem pare i fill
    //cas parell
    if(index%2==0){
        indexParent=(index-2)/2;
    }
    //cas senar
    else{
        indexParent=(index-1)/2;
    }
    this->minHeap.push_back(element);
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
    if(minHeap[indexParent]->getId()>minHeap[index]->getId()){
        //Intercanviem els nodes.
        Type aux;
        aux=minHeap[index];
        minHeap[index]=minHeap[indexParent];
        minHeap[indexParent]=aux;
        this->bubbleUp(indexParent);
    }
       
}

//MinKey
template<class Type> int MinHeap<Type>::min() const{
    if(size()>0){
        return this->minHeap[0]->getId();
    }
    else{
        throw invalid_argument("El MinHeap és buit.");
    }
}

//MinValue
template<class Type> Type MinHeap<Type>::minValue() const{
    if(size()>0){
        return this->minHeap[0];
    }
    else{
        throw invalid_argument("El MinHeap és buit.");
    }
}
#ifdef __cplusplus
#endif

#endif /* MINHEAP_H */

