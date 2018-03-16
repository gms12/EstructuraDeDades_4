/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabriel
 *
 * Created on 6 de marzo de 2018, 8:59
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

#include "ArrayDeque.h"

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

/*
 * 
 */
int main(int argc, char** argv) {
    vector<string> vec_options(6);
    int option, max;
    
    vec_options[0]="Inserir element pel davant";
    vec_options[1]="Inserir element pel final";
    vec_options[2]="Eliminar element pel davant";
    vec_options[3]="Eliminar element pel final";
    vec_options[4]="Imprimir contingut de l’ArrayDEQUE";
    vec_options[5]="Sortir";
    
    cout<<"Introdueix la mida de l'ArrayDEQUE: ";
    cin>>max;
    try{
        ArrayDeque array=new ArrayDeque(max);
        do{
            cout<<"Que vols fer?"<<endl;
            option=menu(vec_options);
            switch(option){
                case 0:break;
                case 1:break;
                case 2:break;
                case 3:break;
                case 4:break;
                case 5:cout<<"Adéu!"<<endl;;
            }
        }while(option!=5);
    }
    catch(invalid_argument& e){
        cout<<e.what()<<endl;
    }
    vec_options.clear();
    vector<string>().swap(vec_options);
    delete vec_options;
    return 0;
}

