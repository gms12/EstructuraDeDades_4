/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mpedembe7.alumnes
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
    bst=new BinarySearchTree<int>();//creem el nou bst
    //inserim els elements de l'array a l'arbre
    for(int i=0;i<8;i++){
        bst->insert(testArray[i]);
    }
    //Imprimir en preordre l’arbre per pantalla
    bst->printPreorder();
    //Imprimir en inordre l’arbre per pantalla
    bst->printInorder();
    //Imprimir en postordre l’arbre per 
    bst->printPostorder();
    //Comrpovacions del height i size
    cout<<"Height: "<<bst->getHeight()<<endl;
    cout<<"Size: "<<bst->size()<<endl;
    //Fer el mirall de l'arbre
    BinarySearchTree<int> *bst_mirror=bst->mirror();
    //Imprimir en preordre el mirall de l'arbre
    bst_mirror->printPreorder();
    
    
    //Eliminar l'arbre
    delete bst;
    delete bst_mirror;
    return 0;
}

