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
    string nom, prioritat, fitxer;
    if(!myFile.is_open()){
        cout << "Unable to open file." << endl;
        return;
    }else{
        while(!myFile.eof()){
            myFile >> nom >> prioritat >> fitxer;
            string element = nom + "\t" + prioritat + "\t" + fitxer;
            if(prioritat == "1") link.insertFront(element);
            else link.insertRear(element);
        }
    }
    cout << "Fitxer afegit a la llista." << endl;
}

void deleteFront(LinkedDeque<string> &link){
    try{
        string element = link.getFront();
        link.deleteFront();
        cout << "Element " << element << " eliminat pel davant." << endl;
    }catch(invalid_argument& e){
        cout<<e.what()<<endl;
    }
}

void deleteRear(LinkedDeque<string> &link){
    try{
        string element = link.getRear();
        link.deleteRear();
        cout << "Element " << element << " eliminat pel darrera." << endl;
    }catch(invalid_argument& e){
        cout<<e.what()<<endl;
    }
}

void addRear(LinkedDeque<string> &link){
    string nom, prioritat, fitxer;
    while(true){
        cout << "Introdueix el teu nom (0 per acabar): ";
        cin >> nom;
        if(nom == "0") break;
        cout << "Introdueix la prioritat (1/2): ";
        cin >> prioritat;
        cout << "Introdueix el nom complet del fitxer: ";
        cin >> fitxer;
        string element = nom + "\t" + prioritat + "\t" + fitxer;
        if(prioritat == "1") link.insertFront(element);
        else link.insertRear(element);
    }
    
    cout << "Elements afegits pel darrera." << endl;
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
                deleteFront(*link);
                break;
            case 2:
                deleteRear(*link);
                break;
            case 3:
                addRear(*link);
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

