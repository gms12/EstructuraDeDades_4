/* 
 * File:   main.cpp
 * Author: Gabriel Marín i Martí Pedemonte
 *
 * Created on 27 de abril de 2018, 13:16
 */

#include <cstdlib>
#include <ctime>
#include <vector>
#include "BalancedBSTMovieFinder.h"
#include "BSTMovieFinder.h"

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
    
    BalancedBSTMovieFinder* bmFinder = new BalancedBSTMovieFinder();
    BSTMovieFinder* mFinder = new BSTMovieFinder();
    //Proves fitxer petit:
    fileName = "movie_rating_small.txt";
    cout<<"--------------------------"<<endl<<"-----SMALL FILE TEST:-----"<<endl<<"--------------------------"<<endl;
        //BST
        cout<<"CREATION BST: "<<endl;
        initialTime = clock();
        mFinder->appendMovies(fileName);
        finalTime = clock();
        cout<<"It took "<< ((float)(finalTime-initialTime))/(CLOCKS_PER_SEC)<<" seconds to append."<<endl<<endl;

        //Balanced
        cout<<"CREATION Balanced: "<<endl;
        initialTime = clock();
        bmFinder->appendMovies(fileName);
        finalTime = clock();
        cout<<"It took "<< ((float)(finalTime-initialTime))/(CLOCKS_PER_SEC)<<" seconds to append."<<endl<<endl;
        
        //BST
        cout<<"SIZE BST: "<<mFinder->getTree()->size()<<endl;
        cout<<"HEIGHT BST: "<<mFinder->getTree()->getHeight()<<endl<<endl;

        //Balanced
        cout<<"SIZE Balanced: "<<bmFinder->getTree()->size()<<endl;
        cout<<"HEIGHT Balanced: "<<bmFinder->getTree()->getHeight()<<endl<<endl;
        
        //BST
        cout<<"SEARCH BST: "<<endl;
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
        cout<<"It took "<< ((float)(finalTime-initialTime))/(CLOCKS_PER_SEC)<<" seconds to search the whole tree."<<endl;
        cout<<"There are "<< isInTree <<" matching movies in the tree."<<endl<<endl;
        myFile.close();
        
        //BALANCED
        cout<<"SEARCH Balanced: "<<endl;
        myFile.open("cercaPelicules.txt");
        isInTree = 0;
        initialTime = clock();
        if(!myFile.is_open()){
            cout<< "Unable to open file."<<endl;
        }else{
            while( getline((myFile), line) ){
                if( bmFinder->searchMovie( atoi(line.c_str()) ) ) isInTree++;
            }
        }
        finalTime = clock();
        cout<<"It took "<< ((float)(finalTime-initialTime))/(CLOCKS_PER_SEC)<<" seconds to search the whole tree."<<endl;
        cout<<"There are "<< isInTree <<" matching movies in the tree."<<endl<<endl;
        myFile.close();

        delete bmFinder;
        delete mFinder;
        
    bmFinder = new BalancedBSTMovieFinder();
    mFinder = new BSTMovieFinder();
    //Proves fitxer petit:
    fileName = "movie_rating.txt";
    cout<<"------------------------"<<endl<<"-----BIG FILE TEST:-----"<<endl<<"------------------------"<<endl;
        //BST
        cout<<"CREATION BST: "<<endl;
        initialTime = clock();
        mFinder->appendMovies(fileName);
        finalTime = clock();
        cout<<"It took "<< ((float)(finalTime-initialTime))/(CLOCKS_PER_SEC)<<" seconds to append."<<endl<<endl;

        //Balanced
        cout<<"CREATION Balanced: "<<endl;
        initialTime = clock();
        bmFinder->appendMovies(fileName);
        finalTime = clock();
        cout<<"It took "<< ((float)(finalTime-initialTime))/(CLOCKS_PER_SEC)<<" seconds to append."<<endl<<endl;
        
        //BST
        cout<<"SIZE BST: "<<mFinder->getTree()->size()<<endl;
        cout<<"HEIGHT BST: "<<mFinder->getTree()->getHeight()<<endl<<endl;

        //Balanced
        cout<<"SIZE Balanced: "<<bmFinder->getTree()->size()<<endl;
        cout<<"HEIGHT Balanced: "<<bmFinder->getTree()->getHeight()<<endl<<endl;
        
        //BST
        cout<<"SEARCH BST: "<<endl;
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
        cout<<"It took "<< ((float)(finalTime-initialTime))/(CLOCKS_PER_SEC)<<" seconds to search the whole tree."<<endl;
        cout<<"There are "<< isInTree <<" matching movies in the tree."<<endl<<endl;
        myFile.close();
        
        //BALANCED
        cout<<"SEARCH Balanced: "<<endl;
        myFile.open("cercaPelicules.txt");
        isInTree = 0;
        initialTime = clock();
        if(!myFile.is_open()){
            cout<< "Unable to open file."<<endl;
        }else{
            while( getline((myFile), line) ){
                if( bmFinder->searchMovie( atoi(line.c_str()) ) ) isInTree++;
            }
        }
        finalTime = clock();
        cout<<"It took "<< ((float)(finalTime-initialTime))/(CLOCKS_PER_SEC)<<" seconds to search the whole tree."<<endl;
        cout<<"There are "<< isInTree <<" matching movies in the tree."<<endl<<endl;
        myFile.close();

    
        delete bmFinder;
        delete mFinder;
    

    return 0;
}