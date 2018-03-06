/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Martí i Gabriel
 *
 * Created on 20 de febrero de 2018, 8:38
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string nom;
    string arr_options[] = {"Sortir", "Benvinguda"};
    int option;
    
    cout<<"Digues el teu nom: ";
    cin>>nom;
    do{
        cout<<"Hola, "<<nom<<", que vols fer?"<<endl;
        for(option=0;option<2;option++){
            cout<<option+1<<".\t"<<arr_options[option]<<endl;
        }
        cin>>option;
        option--;
        if(option!=0 and option!=1){
            cout<<"Opció incorrecte."<<endl;
        }
        else{
            if(option==0)cout<<"Adéu."<<endl;
            else cout<<"Benvingut/da a l'assignatura d'estructura de dades "<<nom<<"."<<endl;
        }
    }while(option!=0);
    return 0;
}

/*Quins tipus de fitxers tens a la carpeta del teu ordinador del projecte? 
 * A què correspon cada tipus?
 A part dels fitxers que corresponen al projecte de netbeans, generats automàticament,
 * tenim l'arxiu principal .cpp, que és on hi ha el codi escrit. També hi ha el 
 * tipus .o, que correspon a l'objecte, un cop compilat el codi. Per últim tenim
 * el .exe, que es tracta de l'arxiu executable, creat a partir de l'objecte. 
 * Aquest últim és el que s'obre a la consola i s'executa.
 */