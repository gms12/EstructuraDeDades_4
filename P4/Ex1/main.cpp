/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabriel
 *
 * Created on 20 de mayo de 2018, 15:29
 */

#include <cstdlib>
#include "MinHeap.h"
#include "Movie.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    MinHeap<Movie> *movies_minHeap;
    movies_minHeap=new MinHeap<Movie>();
    Movie m1(4,"movie1",3.2);
    Movie m2(3,"movie2",1.6);
    Movie m3(8,"movie3",2.6);
    Movie m4(2,"movie4",0.3);
    Movie m5(1,"movie5",4.6);
    try{
        movies_minHeap->insert(m1);
        movies_minHeap->insert(m2);
        movies_minHeap->insert(m3);
        movies_minHeap->insert(m4);
        movies_minHeap->insert(m5);
        movies_minHeap->printHeap();

        cout<<"Minim: "<<movies_minHeap->minValue().toString()<<endl;
        cout<<"Busquem el 8: "<<movies_minHeap->search(8).toString()<<endl;
        cout<<"Size: "<<movies_minHeap->size()<<endl;
        movies_minHeap->removeMin();
        cout<<"Minim: "<<movies_minHeap->minValue().toString()<<endl;
    }
    catch(invalid_argument& e){
        cout<<e.what()<<endl;
    }
    
    delete movies_minHeap;
    return 0;
}

