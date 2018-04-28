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
using namespace std;


class BSTMovieFinder {
    public:
        //Constructors
        BSTMovieFinder();
        BSTMovieFinder(const BSTMovieFinder& orig);
        //Destructor
        virtual ~BSTMovieFinder();
        //Consultores
        string showMovie(const int id);
        Movie findMovie(const int id);
        float findRatingMovie(const int id);
        BinarySearchTree<Movie> getTree();
        //Modificadores
        void appendMovies(const string file);
        void insertMovie(const int id, const string title, const float rating);
        
    private:
        BinarySearchTree<Movie> bst;
};

#endif /* BSTMOVIEFINDER_H */

