/* 
 * File:   main.cpp
 * Author: Gabriel Marín i Martí Pedemonte
 *
 * Created on 30 de maig de 2018, 13:16
 */

#include <cstdlib>
#include <ctime>
#include <vector>
#include "HeapMovieFinder.h"

using namespace std;

/*
 * Main
 */
int main(int argc, char** argv) {
    
    clock_t initialTime, finalTime;
    string fileName;
    ifstream myFile;
    string line;
    int isInTree = 0;
    
    HeapMovieFinder* mFinder;
    //Proves fitxer petit:
    fileName = "movie_rating_small.txt";
    cout<<"--------------------------"<<endl<<"-----SMALL FILE TEST:-----"<<endl<<"--------------------------"<<endl;
        cout<<"CREATION HEAP: "<<endl;
        mFinder = new HeapMovieFinder();
        initialTime = clock();
        mFinder->appendMovies(fileName);
        finalTime = clock();
        cout<<"It took "<< ((float)(finalTime-initialTime))/(CLOCKS_PER_SEC)<<" seconds to append."<<endl<<endl;
        
        cout<<"SIZE HEAP: "<<mFinder->getMinHeap()->size()<<endl;
        cout<<"DEPTH HEAP: "<<mFinder->getMinHeap()->depth()<<endl<<endl;
        
        cout<<"SEARCH HEAP: "<<endl;
        myFile.open("cercaPelicules.txt");
        isInTree = 0;
        initialTime = clock();
        if(!myFile.is_open()){
            cout<< "Unable to open file."<<endl;
        }else{
            while( getline((myFile), line) ){
                if( mFinder->searchMovie( atoi(line.c_str()) ) ) isInTree++;
            }
        }
        finalTime = clock();
        cout<<"It took "<< ((float)(finalTime-initialTime))/(CLOCKS_PER_SEC)<<" seconds to search the whole heap."<<endl;
        cout<<"There are "<< isInTree <<" matching movies in the heap."<<endl<<endl;
        myFile.close();
        
        delete mFinder;
        
    //Proves fitxer petit:
    fileName = "movie_rating.txt";
    cout<<"------------------------"<<endl<<"-----BIG FILE TEST:-----"<<endl<<"------------------------"<<endl;
        cout<<"CREATION HEAP: "<<endl;
        mFinder = new HeapMovieFinder();
        initialTime = clock();
        mFinder->appendMovies(fileName);
        finalTime = clock();
        cout<<"It took "<< ((float)(finalTime-initialTime))/(CLOCKS_PER_SEC)<<" seconds to append."<<endl<<endl;
        
        cout<<"SIZE HEAP: "<<mFinder->getMinHeap()->size()<<endl;
        cout<<"DEPTH HEAP: "<<mFinder->getMinHeap()->depth()<<endl<<endl;
        
        cout<<"SEARCH HEAP: "<<endl;
        myFile.open("cercaPelicules.txt");
        isInTree = 0;
        initialTime = clock();
        if(!myFile.is_open()){
            cout<< "Unable to open file."<<endl;
        }else{
            while( getline((myFile), line) ){
                if( mFinder->searchMovie( atoi(line.c_str()) ) ) isInTree++;
            }
        }
        finalTime = clock();
        cout<<"It took "<< ((float)(finalTime-initialTime))/(CLOCKS_PER_SEC)<<" seconds to search the whole heap."<<endl;
        cout<<"There are "<< isInTree <<" matching movies in the heap."<<endl<<endl;
        myFile.close();

        delete mFinder;
    

    return 0;
}