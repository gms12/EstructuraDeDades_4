/* 
 * File:   main.cpp
 * Author: Gabriel Marín i Martí Pedemonte
 *
 * Created on 27 de abril de 2018, 13:16
 */

#include <cstdlib>
#include <ctime>
#include <vector>
#include "BSTMovieFinder.h"

using namespace std;

//metode per a mostrar el menu
int menu(vector<string> a){
    int i;
    for(i = 0; i<a.size(); i++){
        cout << i+1 << ".\t "<< a[i] << endl;
    }
    cin >> i;
    i--;
    if(i<0 || i >= a.size()){
        cout<<"Opció incorrecte."<<endl;
        return menu(a);
    }
    return i;
}

/*
 * 
 */
int main(int argc, char** argv) {
    /*
    vector<string> vec_options(5);
    int option;

    vec_options[0]="Llegir fitxer";
    vec_options[1]="Mostrar l’arbre segons l’ID en ordre creixent";
    vec_options[2]="Llegir el fitxer cercaPelicules.txt i mostrar nºelements";
    vec_options[3]="Visualitzar per pantalla la profunditat de l'arbre";
    vec_options[4]="Sortir";
    
    do{
        cout<<"Que vols fer?"<<endl;
        option=menu(vec_options);
        switch(option){
            case 0:
                
                break;
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                cout<<"Adéu!"<<endl;
               
        }
    }while(option!=4);
    vec_options.clear();
    vector<string>().swap(vec_options);
    */
    
    //PROVES:
    //---------------
    /*
    BSTMovieFinder* mF = new BSTMovieFinder();
    mF->appendMovies("input");
    mF->getTree()->printPreorder();
    mF->insertMovie(56789, "Harry", 3.4567);
    mF->getTree()->printPreorder();
    Movie m = mF->findMovie(8923);
    cout<<m.toString()<<endl;
    cout<<mF->findRatingMovie(8923)<<endl;
    cout<<mF->showMovie(8923)<<endl;
    delete mF;
    */
    //-------------
    
    //Main demanat:
    string resposta, fileName;
    cout<<"Quin fitxer vols (P/G)? ";
    cin>>resposta;
    while(resposta != "P" && resposta != "G" && resposta != "p" && resposta != "g"){
        cout<<"A veure, no és tan difícil. Quin fitxer vols (P/G)? ";
        cin>>resposta;
    }
    if(resposta == "P" || resposta == "p") fileName = "movie_rating_small.txt";
    else fileName = "movie_rating.txt";
    BSTMovieFinder* mF = new BSTMovieFinder();
    clock_t initialTime = clock();
    //cout<<t<<endl;
    mF->appendMovies(fileName);
    clock_t finalTime = clock();
    //cout<<t<<endl;
    cout<<"It took "<< ((float)(finalTime-initialTime))/(CLOCKS_PER_SEC)<<" seconds."<<endl;
    mF->printAscendingOrder();
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

