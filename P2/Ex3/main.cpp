/*
 * Exercici 3.
 */

/* 
 * File:   main.cpp
 * Author: Martí Pedemonte i Gabriel Marín
 *
 * Created on 14 de abril de 2018, 12:00
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <fstream>

#include "LinkedDeque.h"

using namespace std;

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

void readFile(LinkedDeque<string> &link){
    ifstream myFile;
    myFile.open("input.txt");
    string line;
    if(!myFile.is_open()){
        cout << "Unable to open file." << endl;
        return;
    }else{
        while(getline(myFile, line)){
            link.insertRear(line);
        }
    }
    cout << "Fitxer afegit a la llista." << endl;
}


/*
 * 
 */
int main(int argc, char** argv) {
    vector<string> vec_options(6);
    int option;
    LinkedDeque<string> *link;
    
    vec_options[0]="Llegir un fitxer amb les entrades de la cua d'impressió";
    vec_options[1]="Eliminar una impressió pel davant";
    vec_options[2]="Eliminar una impressió pel final";
    vec_options[3]="Inserir n entrades d'impressió des de teclat (0 per finalitzar)";
    vec_options[4]="Imprimir la cua d'impressió";
    vec_options[5]="Sortir";
    
    
    link=new LinkedDeque<string>();
    do{
        cout<<"Que vols fer?"<<endl;
        option=menu(vec_options);
        switch(option){
            case 0:
                readFile(*link);
                break;
            case 1:
                //insertRear(*link);
                break;
            case 2:
                //deleteFront(*link);
                break;
            case 3:
                //deleteRear(*link);
                break;
            case 4:
                link->print();
                break;
            case 5:cout<<"Adéu!"<<endl;
        }
    }while(option!=5);
    delete link;
    
    vec_options.clear();
    vector<string>().swap(vec_options);
    return 0;
}

