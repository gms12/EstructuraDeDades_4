/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Martí Pedemonte i Gabriel Marín
 *
 * Created on 17 / d’abril / 2018, 08:32
 */

#include <cstdlib>
#include "BinarySearchTree.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int testArray [] = {2, 0, 8, 45, 76, 5, 3, 40 };
    BinarySearchTree<int> *bst;
    bst = new BinarySearchTree<int>();//creem el nou bst
    if(bst->isEmpty()) cout<<"Empty Tree. All OK."<<endl;
    //inserim els elements de l'array a l'arbre
    for(int i=0;i<8;i++){
        bst->insert(testArray[i]);
    }
    if(!bst->isEmpty()) cout<<"Not empty Tree. All OK."<<endl;
    cout<<"Root: "<<bst->root()->getData()<<endl;
    //Imprimir en preordre l’arbre per pantalla
    bst->printPreorder();
    //Imprimir en inordre l’arbre per pantalla
    bst->printInorder();
    //Imprimir en postordre l’arbre per 
    bst->printPostorder();
    //Comprovacions del height i size
    cout<<"Height: "<<bst->getHeight()<<endl;
    cout<<"Size: "<<bst->size()<<endl;
    int element;
    cout<<"Enter an integer: ";
    cin>>element;
    while(!bst->search(element)){
        bst->insert(element);
        bst->printPreorder();
        bst->printInorder();
        bst->printPostorder();
        cout<<"Height: "<<bst->getHeight()<<endl;
        cout<<"Size: "<<bst->size()<<endl;
        cout<<"Enter an integer: ";
        cin>>element;
    }
    cout<<"Out of the loop. The entered element IS in the tree."<<endl;
    //Fer el mirall de l'arbre
    BinarySearchTree<int> *bst_mirror = bst->mirror();
    //const BinarySearchTree<int> *test = bst;
    //BinarySearchTree<int> *bst_mirror1 = new BinarySearchTree<int>(test);
    //Imprimir en preordre el mirall de l'arbre
    bst_mirror->printPreorder();
    
    
    //Eliminar l'arbre
    delete bst;
    //delete bst_mirror; //No podem fer delete si no fem new bst mirror!
    return 0;
}

