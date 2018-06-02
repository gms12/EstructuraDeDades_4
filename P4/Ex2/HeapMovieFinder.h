/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapMovieFinder.h
 * Author: Gabriel Marin i Martí Pedemonte
 *
 * Created on 2 de junio de 2018, 10:32
 */

#ifndef HEAPMOVIEFINDER_H
#define HEAPMOVIEFINDER_H
#include "Movie.h"
#include "MinHeap.h"
#include <string>
using namespace std;

class HeapMovieFinder{
public:
    //CONSTRUCTOR
    HeapMovieFinder();
    //DESTRUCTOR
    virtual ~HeapMovieFinder();
    //MODIFICADORS
    void appendMovies(string filename);
    void insertMovie(int movieID, string title, float rating);
    //CONSULTORS
    string showMovie(int movieID) const;
    Movie findMovie(int movieID) const;
private:
    //ATRIBUTS
    MinHeap<Movie>* minHeap;
    
};
//CONSTRUCTOR DEFECTE
HeapMovieFinder::HeapMovieFinder(){
    this->minHeap=new MinHeap<Movie>();
}
//DESTRUCTOR
HeapMovieFinder::~HeapMovieFinder(){
    delete minHeap;
}
//Metode per inserir els elements continguts en un arxiu
void HeapMovieFinder::appendMovies(string filename){
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
//Metode per inserir una pelicula al minHeap
void HeapMovieFinder::insertMovie(int movieID, string title, float rating){
    Movie* newMovie = new Movie(id, title, rating);
    this->minHeap->insert(*newMovie);
}

//Metode que retorna la informacio d'una pelicula
string HeapMovieFinder::showMovie(int movieID) const{
    try{
        return this->findMovie(movieID).toString();
    }
    catch(invalid_argument& e){
        throw e;
    }
}

//Metode que busca un element al minHeap. Hem canviat respecte el que deia 
//l'enunciat ja que no tenia molt de sentit tenir dos mètodes que fessin el mateix.
Movie HeapMovieFinder::findMovie(int movieID) const{
    try{
        return this->minHeap->search(movieID);
    }
    catch(invalid_argument& e){
        throw e;
    }
}

#endif /* HEAPMOVIEFINDER_H */

