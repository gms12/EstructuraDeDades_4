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
        int min() const;//TEST
        Type minValue() const;//TEST
        void printHeap() const;//TEST
        Type search(int key) const;//TEST
        //Modificadors
        void insert(const Type& element);//TEST:
        void removeMin();//TEST
    private:
        //Metodes privats
        void upHeap(int index);
        void downHeap(int index);
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
    return !(this->size());//si la mida es 0 retornara true, i si es major aleshores false
}
//Insert
template<class Type> void MinHeap<Type>::insert(const Type& element){
    int index=this->size();    
    this->minHeap.push_back(element);
    this->upHeap(index);
}
//Up Heap. Anira pujant i comprovant que tot està bé. Si no canviarà els nodes que toquin
template<class Type> void MinHeap<Type>::upHeap(int index){
    if(index==0)return;
    int indexParent;
    if(index%2==0){
        indexParent=(index-2)/2;
    }
    else{
        indexParent=(index-1)/2;
    }
    if(minHeap[indexParent].getId()>minHeap[index].getId()){
        //Intercanviem els nodes.
        Type aux;
        aux=minHeap[index];
        minHeap[index]=minHeap[indexParent];
        minHeap[indexParent]=aux;
        this->upHeap(indexParent);
    }
       
}
//Down Heap. Anira baixant i comprovant que tot està bé. Si no canviarà els nodes que toquin
template<class Type> void MinHeap<Type>::downHeap(int index){
    int size = minHeap.size();
    int indexLeftChild = 2*index + 1;
    int indexRightChild = 2*index + 2;

    if(indexLeftChild >= size)
        return; //Es una fulla

    int minIndex = index;
    //Comprovem el fill de l'esq
    if(minHeap[index].getId() > minHeap[indexLeftChild].getId())
    {
        minIndex = indexLeftChild;
    }
    //Comprovem ara el fill de la dreta. Nomes l'agafem si es mes petit que el de l'esq
    if((indexRightChild < size) && (minHeap[minIndex].getId() > minHeap[indexRightChild].getId()))
    {
        minIndex = indexRightChild;
    }

    if(minIndex != index){
        //Fem el canvi
        Type aux = minHeap[index];
        minHeap[index] = minHeap[minIndex];
        minHeap[minIndex] = aux;
        downHeap(minIndex);
    }
       
}
//MinKey
template<class Type> int MinHeap<Type>::min() const{
    if(size()>0){
        return this->minHeap[0].getId();
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
//PrintHeap
template<class Type> void MinHeap<Type>::printHeap() const{}

//Search
template<class Type> Type MinHeap<Type>::search(int key) const{}

//RemoveMin
template<class Type> void MinHeap<Type>::removeMin() const{
    if(size()>0){
        //Primer intercanviem el primer element amb l'ultim
        Type aux=minHeap[0];
        minHeap[0]=minHeap[size()-1];
        minHeap[size()-1]=aux;
        //Ara eliminem l'ultim
        minHeap.pop_back();
        //Ara fem un downHeap
        downHeap(0);
    }
    else{
        throw invalid_argument("El MinHeap és buit.");
    }
}
#ifdef __cplusplus
#endif

#endif /* MINHEAP_H */

