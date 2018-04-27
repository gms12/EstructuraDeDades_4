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
    Movie(string s,float r, int i);
    Movie(const Movie& orig);
    //Destructor
    virtual ~Movie();
    //Consultors
    string getName()const;
    float getRating()const;
    int getID()const;
    string toString() const;
    //Modificadors
    void setName(string s);
    void setRating(float r);
    void setID(int i);
private:
    //Atributs
    string name;
    float rating;
    int ID;
    

};

#endif /* MOVIE_H */

