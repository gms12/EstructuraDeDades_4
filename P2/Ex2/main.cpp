/*
 * Main per a comprovar el correcte funcionament de. TAD LinkedDeque.
 */

/* 
 * File:   main.cpp
 * Author: Martí Pedemonte i Gabriel Marín
 *
 * Created on 20 de marzo de 2018, 8:23
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

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

void insertFront(LinkedDeque<string> &link){
    string element;
    cout << "Introdueix l'element a inserir: ";
    cin >> element;
    link.insertFront(element);
    cout << "Element " << element << " agregat pel davant." << endl;
}

void insertRear(LinkedDeque<string> &link){
    string element;
    cout << "Introdueix l'element a inserir: ";
    cin >> element;
    link.insertRear(element);
    cout << "Element " << element << " agregat pel darrera." << endl;
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
void print(LinkedDeque<string> &link){
    try{
        link.print();
    }catch(invalid_argument& e){
        cout<<e.what()<<endl;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    vector<string> vec_options(6);
    int option;
    LinkedDeque<string> *link;
    
    vec_options[0]="Inserir element pel davant";
    vec_options[1]="Inserir element pel final";
    vec_options[2]="Eliminar element pel davant";
    vec_options[3]="Eliminar element pel final";
    vec_options[4]="Imprimir contingut del LinkdeDeque";
    vec_options[5]="Sortir";
    
    link = new LinkedDeque<string>();
    do{
        cout<<"Que vols fer?"<<endl;
        option=menu(vec_options);
        switch(option){
            case 0:
                insertFront(*link);
                break;
            case 1:
                insertRear(*link);
                break;
            case 2:
                deleteFront(*link);
                break;
            case 3:
                deleteRear(*link);
                break;
            case 4:
                print(*link);
                break;
            case 5:cout<<"Adéu!"<<endl;;
        }
    }while(option!=5);
    delete link;
    vec_options.clear();
    vector<string>().swap(vec_options);
    return 0;
}

/*
 * PREGUNTES
 * 1- Sí que hem utilitzat templates. D'aquesta manera, l'usuari pot utilitzar
 * aquest TAD amb qualsevol tipus de dada que desitgi, ja sigui pròpia del 
 * llenguatge com ho seria int, string, bool, etc o bé una classe que es programi.
 * 
 * 2- COST TEÒRIC: A partir d'ara considerem n com el nombre d'elements que conté.
 *      -constructor defecte: Creem dos punters a node i els assignem. Per tant el 
 *      cost és constant, O(1).
 *      -constructor alternatiu: Com abans, però ara recorrem la cua que es passa
 *      per paràmetre, cost lineal. O(n).
 *      -destructor: Fem un loop per eliminar cada element de la cua, és a dir
 *      recorrem el loop n vegades, cost lineal. O(n).
 *      -size: Retornem un valor, per tant constant. O(1).
 *      -isEmpty: Comprovem que n sigui 0, per tant constant. O(1).
 *      -insertFront: Creem un nou node i movem 4 enllaços, per tant el cost és
 *      constant. O(1).
 *      -insertRear: Igual que abans, cost constant. O(1).
 *      -deleteFront: Similar al cas d'afegir. Apuntem al node de davant, canviem
 *      4 enllaços i aleshores l'eliminem. No recorrem res, cost constant. O(1).
 *      -deleteRear: El mateix cas que l'anterior, però seleccionant el node final, 
 *      però com hem utilitzat enllaços doble, no hem de recòrrer res, sinó que
 *      ja tenim apuntat el node final. Cost constant, O(1).
 *      -print: Aquí sí que recorrem la cua, per tal d'imprimir cada element en 
 *      el seu ordre. Cost lineal, O(n).
 *      -getFront: Simplement retornem l'element del node que apunta el front 
 *      (fent un next ja que hi ha el sentinella). Per tant cost constant, O(1).
 *      -getRear: Com abans, i al tenir enllaç doble podem fer la selecció directe
 *      pel final amb el punter rear. Cost constant, O(1).
 * 
 * 3- De fet hagués estat pitjor fer-ho amb encadenament simple, ja que no podriem
 * inserir o esborrar per darrera de la cua sense haver de recòrrer la cua sencera
 * des del davant (si ho haguéssim implementat amb encadenament simple del tipus next).
 * Per tant, el cost teòric per als mètodes insertRear i deleteRear hauria estat
 * lineal, O(n).
 */