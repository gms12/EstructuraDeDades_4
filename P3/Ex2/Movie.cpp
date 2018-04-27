/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Movie.cpp
 * Author: Martí Pedemonte i Gabriel Marín
 * 
 * Created on 27 de abril de 2018, 13:23
 */

#include "Movie.h"
//Constructor per defecte
Movie::Movie() {
    this->ID=NULL;
    this->rating=NULL;
    this->name="";
         
}
//Constructor per parametres
Movie::Movie(string s, float r, int i){
    this->ID=i;
    this->rating=r;
    this->name=s;
}
//Constructor copia
Movie::Movie(const Movie& orig) {
    this->ID=orig->ID;
    this->rating=orig->rating;
    this->name=orig->name;
}

Movie::~Movie() {
}
//Retorna el nom de Movie
string Movie::getName() const{
    return this->name;
}
//Retorna la puntuacio de Movie
float Movie::getRating() const{
    return this->rating;
}
//Retorna el ID de Movie
int Movie::getID() const{ 
    return this->ID;
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
void Movie::setID(int i){
    this->ID=i;
}
//Retorna una string amb la info de Movie
string Movie::toString() const{
    string rt=to_string(this->rating);
    string id=to_string(this->ID);
    return id+"::"+this->name+"::"+rt;
}