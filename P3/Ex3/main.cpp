/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabriel i Martí
 *
 * Created on 1 de mayo de 2018, 20:45
 */

#include <cstdlib>
#include <string>
#include <fstream>
#include "BalancedBST.h"
using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
    BalancedBST<Movie>* bst=new BalancedBST<>();
    ifstream myFile;
    string filename="movie_rating.txt";
    myFile.open(filename);
    int id;
    string movieName, input;
    float rating;
    //Afegim les movies a l'arbre
    if(!myFile.is_open()){
        cout<<"Unable to open file."<<endl;;
        return;
    }else{
        while(getline((myFile), input)){
            int found1 = input.find("::");//Busco primera aparició de ::
            int found2 = input.find("::", found1+1);//Busco segona aparició de ::
            string sub1 = input.substr(0,found1);//Busco id
            movieName = input.substr(found1+2, found2-(found1+2) );//Busco nom
            string sub3 = input.substr(found2+2);//Busco rating
            
            id = atoi(sub1.c_str());
            rating = atof(sub3.c_str());

            Movie* newMovie = new Movie(id, movieName, rating);  
            bst->insert(*newMovie, id);
        }
    }
    ////////COMPROVAR METODES////////
    
    cout<<bst->getTitleMaxLen()<<endl;
    
    //Nou arbre per a comprovar el funcionament correcte del balanceig
    
    
    myFile.close();
    delete bst;
    return 0;
}

