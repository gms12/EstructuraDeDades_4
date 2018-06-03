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
#include <fstream>
#include <stdexcept>
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
    void printAscendingOrder();
    MinHeap<Movie>* getMinHeap() const;
    bool searchMovie(const int id);
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
    Movie* newMovie = new Movie(movieID, title, rating);
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
//Imprimeix segons ordre creixent
void HeapMovieFinder::printAscendingOrder() {
    //Primer creem un nou minHeap, d'on anirem imprimint el mes petit
    MinHeap<Movie>* minHeapAux= new MinHeap<Movie>(*(this->minHeap));
    int counter=0;//posem el comptador a zero
    string resposta;
    do{
        if(counter<39){//mentres no arribem a 40, anem imprimint
            cout<<minHeapAux->minValue().toString()<<endl;//imprimim el valor amb id mes baix
            minHeapAux->removeMin();//l'eliminem del minHeap, per a tenir sempre el mes petit a dalt
            counter++;//augmentem el comptador
        }
        else{//preguntem si l'usuari vol seguir veient pelicules
            cout<<"Vols seguir veient pel·licules (Y/N)?";
            cin>>resposta;
            while(resposta != "Y" && resposta != "N" && resposta != "y" && resposta != "n"){
                    cout<<"Recorda, respon Y o N";
                    cin>>resposta;
                }
            if(resposta =="Y" || resposta=="y"){
                counter=0;
            }
            else counter++;
        }
    }while(counter<40 && minHeapAux->size()>0);//si el comptador arriba a 40, sortim
}
//Getter del minHeap
MinHeap<Movie>* HeapMovieFinder::getMinHeap() const{
    return this->minHeap;
}
//Metode que busca una Movie en el minHeap donat el seu id
bool HeapMovieFinder::searchMovie(const int id){
    try{
        Movie movie=this->minHeap->search(id);
        return true;
    }
    catch(invalid_argument& e){
        return false;
    }
}
#endif /* HEAPMOVIEFINDER_H */

