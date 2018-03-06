/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Martí i Gabriel
 *
 * Created on 20 de febrero de 2018, 9:05
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "circle.h"

using namespace std;

int menu(vector<string> a){
    int i;
    for(i=0;i<a.size();i++){
            cout<<i+1<<".\t"<<a[i]<<endl;
        }
        cin>>i;
        i--;
        if(i<0 or i>=a.size()){
            cout<<"Opció incorrecte."<<endl;
            return menu(a);
        }
        return i;
}
void crearCercle(int& compt){
    float radi;
    cout<<"Cercle número "<<compt<<"."<<endl;
    cout<<"Radi?"<<endl;
    cin>>radi;
    try{
        Circle c(radi);
        cout<<"L’àrea d’aquest cercle és de "<<c.getArea()<<"."<<endl;
        compt++;
    }
    catch(invalid_argument& e){
        cout<<e.what()<<endl;
    }
}
/*
 * 
 */
int main(int argc, char** argv) {
    vector<string> vec_options(2);
    int option;
    int comptador=1;
    
    vec_options[0]="Sortir";
    vec_options[1]="Introduir cercle";
    
    do{
        cout<<"Hola, que vols fer?"<<endl;
        option=menu(vec_options);
        switch(option){
            case 0:cout<<"Adéu"<<endl;break;
            case 1:crearCercle(comptador);break;
        }
    }while(option!=0);
    
    vec_options.clear();
    vector<string>().swap(vec_options);
    return 0;
}



