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
#include "Movie.h"
using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
    BalancedBST<Movie>* bst=new BalancedBST<Movie>();
    ifstream myFile;
    string filename="movie_rating.txt";
    myFile.open(filename);
    int id;
    string movieName, input;
    float rating;
    //Afegim les movies a l'arbre
    if(!myFile.is_open()){
        cout<<"Unable to open file."<<endl;;
        return 1;
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
    cout<<"Height: "<<bst->getHeight()<<endl;
    cout<<"Size: "<<bst->size()<<endl;
    cout<<endl<<"Títol de pel·lícula més llarg: "<<bst->getTitleMaxLen()<<endl<<endl;
    cout<<"Pel·licules millor puntuades amb un "<<bst->getRatingMax()<<":"<<endl;
    bst->searchMovieRating(bst->getRatingMax());
    cout<<endl;
    cout<<"Pel·licules pitjor puntuades amb un "<<bst->getRatingMin()<<":"<<endl;
    bst->searchMovieRating(bst->getRatingMin());
    cout<<endl;
    
    //Nou arbre per a comprovar el funcionament correcte del balanceig
    int testArray [] = {2, 0, 8, 45, 76, 5, 3, 40 };
    Movie testMovie[]={Movie(2,"hola",3.89),Movie(0,"ha",3.12),Movie(8,"i a", 1.21),Movie(45, "jajsasa", 4.21)};
    BalancedBST<Movie> *bst2;
    bst2 = new BalancedBST<Movie>();//creem el nou bst
    if(bst2->isEmpty()) cout<<"Empty Tree. All OK."<<endl;
    //inserim els elements de l'array a l'arbre
    for(int i=0;i<4;i++){
        bst2->insert(testMovie[i],testMovie[i].getId());
    }
    if(!bst2->isEmpty()) cout<<"Not empty Tree. All OK."<<endl;
    //Imprimir en preordre l’arbre per pantalla
    bst2->printPreorder();
    //Imprimir en inordre l’arbre per pantalla
    bst2->printInorder();
    //Imprimir en postordre l’arbre per 
    bst2->printPostorder();
    //Comprovacions del height i size
    cout<<"Height: "<<bst2->getHeight()<<endl;
    cout<<"Size: "<<bst2->size()<<endl;
    
    cout<<"Títol de pel·lícula més llarg: "<<bst2->getTitleMaxLen()<<endl;
    cout<<"Pel·licules millor puntuades amb un "<<bst2->getRatingMax()<<":"<<endl;
    bst->searchMovieRating(bst->getRatingMax());
    cout<<endl;
    cout<<"Pel·licules pitjor puntuades amb un "<<bst2->getRatingMin()<<":"<<endl;
    bst->searchMovieRating(bst->getRatingMin());
    cout<<endl;
    
    //Fer el mirall de l'arbre
    BalancedBST<Movie> *bst_mirror2 = bst2->mirror();
    //const BinarySearchTree<int> *test = bst;
    //BinarySearchTree<int> *bst_mirror1 = new BinarySearchTree<int>(test);
    //Imprimir en preordre el mirall de l'arbre
    bst_mirror2->printPreorder();
    
    myFile.close();
    delete bst;
    delete bst2;
    delete bst_mirror2;
    return 0;
}

