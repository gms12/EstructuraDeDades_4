/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabriel i Martí
 *
 * Created on 20 de febrero de 2018, 9:05
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int menu(vector<string> a){
    int i;
    for(i=0;i<a.size();i++){
            cout<<i+1<<".\t"<<a[i]<<endl;
        }
        cin>>i;
        i--;
        if(i<0 or i>=a.size()){
            cout<<"Opció incorrecte. Recorda que has de seleccionar 1,2 o 3."<<endl;
            return menu(a);
        }
        return i;
}
/*
 * 
 */
int main(int argc, char** argv) {
    string nom;
    vector<string> vec_options(3);
    int option;
    
    vec_options[0]="Sortir";
    vec_options[1]="Benvinguda";
    vec_options[2]="Redefinir el nom";
    cout<<"Digues el teu nom: ";
    cin>>nom;
    do{
        cout<<"Hola, "<<nom<<", que vols fer?"<<endl;
        option=menu(vec_options);
        switch(option){
            case 0:cout<<"Adéu"<<endl;break;
            case 1:cout<<"Benvingut/da a l'assignatura d'estructura de dades "<<nom<<"."<<endl;break;
            case 2:cout<<"Digues el teu nom: ";cin>>nom;break;
        }
    }while(option!=0);
    
    vec_options.clear();
    vector<string>().swap(vec_options);
    return 0;
}

//No he tingut cap dubte