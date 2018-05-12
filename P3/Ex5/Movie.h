/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Movie.h
 * Author: Martí Pedemonte i Gabriel Marín
 *
 * Created on 27 de abril de 2018, 13:23
 */

#ifndef MOVIE_H
#define MOVIE_H
#include <string>
using namespace std;

class Movie {
    public:
        //Constructors
        Movie();
        Movie(int i, string s, float r);
        Movie(const Movie& orig);
        //Destructor
        virtual ~Movie();
        //Consultors
        string getName()const;
        float getRating()const;
        int getId()const;
        string toString() const;
        //Modificadors
        void setName(string s);
        void setRating(float r);
        void setId(int i);
    private:
        //Atributs
        string name;
        float rating;
        int id;
};


//Constructor per defecte
Movie::Movie() {
    this->id = -1;
    this->rating = -1;
    this->name="";  
}

//Constructor per parametres
Movie::Movie(int i, string s, float r){
    this->id=i;
    this->rating=r;
    this->name=s;
}

//Constructor copia
Movie::Movie(const Movie& orig) {
    this->id=orig.id;
    this->rating=orig.rating;
    this->name=orig.name;
}

//Destructor
Movie::~Movie() {}

//Retorna el nom de Movie
string Movie::getName() const{
    return this->name;
}

//Retorna la puntuacio de Movie
float Movie::getRating() const{
    return this->rating;
}

//Retorna el ID de Movie
int Movie::getId() const{ 
    return this->id;
}

//Modifica el nom de Movie
void Movie::setName(string s){
    this->name=s;
}

//Modifica la puntuacio de Movie
void Movie::setRating(float r){
    this->rating=r;
}

//Modifica el ID de Movie
void Movie::setId(int i){
    this->id=i;
}

//Retorna una string amb la info de Movie
string Movie::toString() const{
    string rt=to_string(this->rating);
    //string id=to_string(this->id);
    return id+"::"+this->name+"::"+rt;
    //return this->name+"::"+rt;
}


#endif /* MOVIE_H */

