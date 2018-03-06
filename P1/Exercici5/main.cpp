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
#include <fstream>


#include "circle.h"
#include "Ellipse.h"

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
void crearFigura(int& cC,int& cE){
    string type;
    float r1,r2;
    cout<<"Quin tipus de figura vols? Tecleja C per a cercle o E per el·lipse: ";
    cin>>type;
    if(type=="C"){
        cin>>r1;
        try{
            cout<<"Introdueix el radi: ";
            Circle c(r1);
            cC++;
            cout<<"Cercle número "<<cC<<"."<<endl;
            cout<<"L’àrea d’aquest cercle és de "<<c.getArea()<<"."<<endl;  
        }
        catch(invalid_argument& e){
            cout<<e.what()<<endl;
        }
    }
    else if(type=="E"){
        cout<<"Introdueix els radis: ";
        cin>>r1>>r2;
        try{
            Ellipse e(r1,r2);
            cE++;
            cout<<"El·lipse número "<<cE<<"."<<endl;
            cout<<"L’àrea d’aquesta el·lipse és de "<<e.getArea()<<"."<<endl;  
        }
        catch(invalid_argument& e){
            cout<<e.what()<<endl;
        }
    }
    else{
        cout<<"Atenció: introdueix C per a cercle i E per l'el·lipse."<<endl;
        crearFigura(cC, cE);
    }
    
}
void mostrarGlosari(int a,int b){
    cout<<"Tens "<<a<<" cercles i "<<b<<" el·lipses."<<endl;
}
void llegirFigures(int& cC,int& cE){
    string nom_fitxer;
    ifstream file;
    string type;
    float r1,r2;
    cout<<"Introdueix el nom o adreça del fitxer: ";
    cin>>nom_fitxer;
    file.open(nom_fitxer);
    if(file.fail()){
        cout<<"Error al llegir l'arxiu "<<nom_fitxer.c_str()<<"."<< endl;
    }
    else{
        while(!file.eof()){
            file>>type;
            if(type=="C"){
                file>>r1;
                try{
                    Circle c(r1);
                    cC++;
                    cout<<"Cercle número "<<cC<<"."<<endl;
                    cout<<"L’àrea d’aquest cercle és de "<<c.getArea()<<"."<<endl;  
                }
                catch(invalid_argument& e){
                    cout<<e.what()<<endl;
                }
            }
            else if(type=="E"){
                file>>r1;
                file>>r2;
                try{
                    Ellipse e(r1,r2);
                    cE++;
                    cout<<"El·lipse número "<<cE<<"."<<endl;
                    cout<<"L’àrea d’aquesta el·lipse és de "<<e.getArea()<<"."<<endl;  
                }
                catch(invalid_argument& e){
                    cout<<e.what()<<endl;
                }
            }
            else{
                cout<<"Dada incorrecte."<<endl;
            }
        }
    }
    file.close();
}
/*
 * 
 */
int main(int argc, char** argv) {
    vector<string> vec_options(4);
    int option;
    int c_cercle=0;
    int c_elipse=0;

    vec_options[0]="Sortir";
    vec_options[1]="Afegir figura";
    vec_options[2]="Glossari de figures";
    vec_options[3]="LLegir figures d'un fitxer";
    
    do{
        cout<<"Hola, que vols fer?"<<endl;
        option=menu(vec_options);
        switch(option){
            case 0:cout<<"Adéu"<<endl;break;
            case 1:crearFigura(c_cercle,c_elipse);break;
            case 2:mostrarGlosari(c_cercle,c_elipse);
            case 3:llegirFigures(c_cercle,c_elipse);
        }
    }while(option!=0);
    
    vec_options.clear();
    vector<string>().swap(vec_options);
    return 0;
}



