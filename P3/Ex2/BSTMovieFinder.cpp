/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTMovieFinder.cpp
 * Author: Gabriel Marín i Martí Pedemonte
 * 
 * Created on 27 de abril de 2018, 14:06
 */

#include "BSTMovieFinder.h"
    
//Constructor per defecte
BSTMovieFinder::BSTMovieFinder() {
    this->bst = new BinarySearchTree<Movie>();
}

//Constructor còpia
BSTMovieFinder::BSTMovieFinder(const BSTMovieFinder& orig) {
    this->bst = new BinarySearchTree<Movie>( orig.getTree() );
}

//Destructor
BSTMovieFinder::~BSTMovieFinder() {
    delete this->bst;
}

//Mostra la informació d'una película donat el seu id
string BSTMovieFinder::showMovie(const int id) {
    this->bst.search(id);
}

//Retorna el seu bst
BinarySearchTree<Movie> BSTMovieFinder::getTree() {
    return this->bst;
}

