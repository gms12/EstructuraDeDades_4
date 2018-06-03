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
    Movie m1(22,"movie1",3.2);
    Movie m2(15,"movie2",1.6);
    Movie m3(36,"movie3",2.6);
    Movie m4(44,"movie4",0.3);
    Movie m5(10,"movie5",4.6);
    Movie m6(3,"movie6",2.6);
    Movie m7(9,"movie7",1.6);
    Movie m8(13,"movie8",1.5);
    Movie m9(29,"movie9",1.6);
    Movie m10(25,"movie10",1.6);
    Movie m11(2,"movie11",1.6);
    Movie m12(11,"movie12",1.6);
    Movie m13(7,"movie13",1.6);
    Movie m14(1,"movie14",1.6);
    Movie m15(17,"movie15",1.6);
    try{
        movies_minHeap->insert(m1);
        movies_minHeap->insert(m2);
        movies_minHeap->insert(m3);
        movies_minHeap->insert(m4);
        movies_minHeap->insert(m5);
        movies_minHeap->insert(m6);
        movies_minHeap->insert(m7);
        movies_minHeap->insert(m8);
        movies_minHeap->insert(m9);
        movies_minHeap->insert(m10);
        movies_minHeap->insert(m11);
        movies_minHeap->insert(m12);
        movies_minHeap->insert(m13);
        movies_minHeap->insert(m14);
        movies_minHeap->insert(m15);
        movies_minHeap->printHeap();

        cout<<"Minim: "<<movies_minHeap->minValue().toString()<<endl;
        cout<<"Busquem el 8: "<<movies_minHeap->search(25).toString()<<endl;
        cout<<"Size: "<<movies_minHeap->size()<<endl;
        movies_minHeap->removeMin();
        cout<<"Minim: "<<movies_minHeap->minValue().toString()<<endl;
        cout<<"minim: "<<movies_minHeap->min()<<endl;
        
    }
    catch(invalid_argument& e){
        cout<<e.what()<<endl;
    }
    
    delete movies_minHeap;
    return 0;
}

