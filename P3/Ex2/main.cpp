/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabriel Marín i Martí Pedemonte
 *
 * Created on 27 de abril de 2018, 13:16
 */

#include <cstdlib>
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
    BSTMovieFinder* mF = new BSTMovieFinder();
    
    return 0;
}

