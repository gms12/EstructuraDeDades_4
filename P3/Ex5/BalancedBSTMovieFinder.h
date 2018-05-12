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

#ifndef BALANCEDBSTMOVIEFINDER_H
#define BALANCEDBSTMOVIEFINDER_H
#include "Movie.h"
#include "BalancedBST.h"
#include "NodeTree.h"
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;


class BalancedBSTMovieFinder {
    public:
        //Constructors
        BalancedBSTMovieFinder();//Test: OK
        BalancedBSTMovieFinder(const BalancedBSTMovieFinder& orig);//TEST: OK
        //Destructor
        virtual ~BalancedBSTMovieFinder();//TEST: OK
        //Consultores
        string showMovie(const int id);//TEST: OK
        Movie findMovie(const int id);//TEST: OK
        float findRatingMovie(const int id);//TEST: OK
        bool searchMovie(const int id);//TEST: OK
        BalancedBST<Movie>* getTree() const;//TEST: OK
        void printAscendingOrder();//TEST: OK
        //Modificadores
        void appendMovies(const string filename);//TEST: OK
        void insertMovie(const int id, const string title, const float rating);//TEST: OK
        
    private:
        BalancedBST<Movie>* bst;
};


//Constructor per defecte
BalancedBSTMovieFinder::BalancedBSTMovieFinder() {
    this->bst = new BalancedBST<Movie>();
}

//Constructor còpia
BalancedBSTMovieFinder::BalancedBSTMovieFinder(const BalancedBSTMovieFinder& orig) {
    this->bst = new BalancedBST<Movie>( *orig.getTree() );
}

//Destructor
BalancedBSTMovieFinder::~BalancedBSTMovieFinder() {
    delete this->bst;
}

//Mostra la informació d'una pel·lícula donat el seu id
string BalancedBSTMovieFinder::showMovie(const int id) {
    try{
        return this->findMovie(id).toString();
    }catch(invalid_argument& e){
        throw e;
    }
}

//Mostra la Movie donat el seu id
Movie BalancedBSTMovieFinder::findMovie(const int id) {
    NodeTree<Movie>* movieNode = this->bst->search(id);
    if( movieNode == nullptr ){
        throw invalid_argument("Movie not in tree.");
    }else{
        return movieNode->getValue();
    }
}

//Busca la Movie donat el seu id
bool BalancedBSTMovieFinder::searchMovie(const int id) {
    NodeTree<Movie>* movieNode = this->bst->search(id);
    if( movieNode == nullptr ){
        return false;
    }else{
        return true;
    }
}

//Mostra la puntuació d'una pel·lícula donat el seu id
float BalancedBSTMovieFinder::findRatingMovie(const int id) {
    try{
        return this->findMovie(id).getRating();
    }catch(invalid_argument& e){
        throw e;
    }
}

//Retorna el seu bst
BalancedBST<Movie>* BalancedBSTMovieFinder::getTree() const{
    return this->bst;
}

//Afegeix movies a partir d'un fitxer
void BalancedBSTMovieFinder::appendMovies(const string filename) {
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
   
    myFile.close();
}

//Afegeix una movie donada tota la seva informació
void BalancedBSTMovieFinder::insertMovie(const int id, const string title, const float rating) {
    Movie* newMovie = new Movie(id, title, rating);
    this->bst->insert(*newMovie, id);
}

//Imprimeix segons ordre creixent
void BalancedBSTMovieFinder::printAscendingOrder() {
    this->bst->printInorder();
}

#endif /* BALANCEDBSTMOVIEFINDER_H */

