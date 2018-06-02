/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapMovieFinder.h
 * Author: Gabriel
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
    void findMovie(int movieID);
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
HeapMovieFinder::appendMovies(string filename){}
HeapMovieFinder::insertMovie(int movieID, string title, float rating){}
HeapMovieFinder::showMovie(int movieID) const{}
HeapMovieFinder::findMovie(int movieID){}

#endif /* HEAPMOVIEFINDER_H */

