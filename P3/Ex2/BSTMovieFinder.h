/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTMovieFinder.h
 * Author: Martí Pedemonte i Gabriel Marín
 *
 * Created on 27 de abril de 2018, 14:06
 */

#ifndef BSTMOVIEFINDER_H
#define BSTMOVIEFINDER_H
#include "Movie.h"
#include "BinarySearchTree.h"
#include "NodeTree.h"
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;


class BSTMovieFinder {
    public:
        //Constructors
        BSTMovieFinder();//Test: OK
        BSTMovieFinder(const BSTMovieFinder& orig);//TEST: OK
        //Destructor
        virtual ~BSTMovieFinder();//TEST: OK
        //Consultores
        string showMovie(const int id);//TEST: OK
        Movie findMovie(const int id);//TEST: OK
        float findRatingMovie(const int id);//TEST: OK
        BinarySearchTree<Movie>* getTree() const;//TEST: OK
        //Modificadores
        void appendMovies(const string filename);//TEST: OK
        void insertMovie(const int id, const string title, const float rating);//TEST: OK
        
    private:
        BinarySearchTree<Movie>* bst;
};


//Constructor per defecte
BSTMovieFinder::BSTMovieFinder() {
    this->bst = new BinarySearchTree<Movie>();
}

//Constructor còpia
BSTMovieFinder::BSTMovieFinder(const BSTMovieFinder& orig) {
    this->bst = new BinarySearchTree<Movie>( *orig.getTree() );
}

//Destructor
BSTMovieFinder::~BSTMovieFinder() {
    delete this->bst;
}

//Mostra la informació d'una pel·lícula donat el seu id
string BSTMovieFinder::showMovie(const int id) {
    try{
        return this->findMovie(id).toString();
    }catch(invalid_argument& e){
        throw e;
    }
}

//Mostra la Movie donat el seu id
Movie BSTMovieFinder::findMovie(const int id) {
    NodeTree<Movie>* movieNode = this->bst->search(id);
    if( movieNode == nullptr){
        throw invalid_argument("Movie not in tree.");
    }else{
        return movieNode->getValue();
    }
}

//Mostra la puntuació d'una pel·lícula donat el seu id
float BSTMovieFinder::findRatingMovie(const int id) {
    try{
        return this->findMovie(id).getRating();
    }catch(invalid_argument& e){
        throw e;
    }
}

//Retorna el seu bst
BinarySearchTree<Movie>* BSTMovieFinder::getTree() const{
    return this->bst;
}

//Afegeix movies a partir d'un fitxer
void BSTMovieFinder::appendMovies(const string filename) {
    ifstream myFile;
    myFile.open(filename);
    int id;
    string movieName, input;
    float rating;
    
    if(!myFile.is_open()){
        throw invalid_argument("Unable to open file.");
        return;
    }else{
        while( getline((myFile), input) ){
            int found1 = input.find("::");//Busco primera aparició de ::
            int found2 = input.find("::", found1+1);//Busco segona aparició de ::
            string sub1 = input.substr(0,found1);//Busco id
            movieName = input.substr(found1+2, found2-(found1+2) );//Busco nom
            string sub3 = input.substr(found2+2);//Busco rating
            
            id = atoi(sub1.c_str());
            rating = atof(sub3.c_str());

            this->insertMovie(id, movieName, rating);
        }
    }
}

//Afegeix una movie donada tota la seva informació
void BSTMovieFinder::insertMovie(const int id, const string title, const float rating) {
    Movie* newMovie = new Movie(id, title, rating);
    this->bst->insert(*newMovie, id);
    
}

#endif /* BSTMOVIEFINDER_H */

