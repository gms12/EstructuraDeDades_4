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
    delete &vec_options;
    return 0;
}

