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
#include "EllipseContainer.h"

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
void crearFigura(int& cC,int& cE,Ellipse *p,EllipseContainer *cont){
    string type;
    float r1,r2;
    cout<<"Quin tipus de figura vols? Tecleja C per a cercle o E per el·lipse: ";
    cin>>type;
    if(type=="C"){
        cout<<"Introdueix el radi: ";
        cin>>r1;
        try{
            p=new Circle(r1);
            cC++;
            cout<<"Cercle número "<<cC<<"."<<endl;
            cout<<"L’àrea d’aquest cercle és de "<<p->getArea()<<"."<<endl;
            try{
                cont->addEllipse(p);
            }
            catch(invalid_argument& e){
                cout<<e.what()<<endl;
            }
        }
        catch(invalid_argument& e){
            cout<<e.what()<<endl;
        }
    }
    else if(type=="E"){
        cout<<"Introdueix els radis: ";
        cin>>r1>>r2;
        try{
            p= new Ellipse(r1,r2);
            cE++;
            cout<<"El·lipse número "<<cE<<"."<<endl;
            cout<<"L’àrea d’aquesta el·lipse és de "<<p->getArea()<<"."<<endl;
            try{
                cont->addEllipse(p);
            }
            catch(invalid_argument& e){
                cout<<e.what()<<endl;
            }
        }
        catch(invalid_argument& e){
            cout<<e.what()<<endl;
        }
    }
    else{
        cout<<"Atenció: introdueix C per a cercle i E per l'el·lipse."<<endl;
        crearFigura(cC, cE,p,cont);
    }
    
}
void mostrarGlosari(int a,int b){
    cout<<"Tens "<<a<<" cercles i "<<b<<" el·lipses."<<endl;
}
void llegirFigures(int& cC,int& cE,Ellipse *p,EllipseContainer *cont){
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
                    p=new Circle(r1);
                    cC++;
                    cout<<"Cercle número "<<cC<<"."<<endl;
                    cout<<"L’àrea d’aquest cercle és de "<<p->getArea()<<"."<<endl; 
                    try{
                        cont->addEllipse(p);
                    }
                    catch(invalid_argument& e){
                        cout<<e.what()<<endl;
                    }
                }
                catch(invalid_argument& e){
                    cout<<e.what()<<endl;
                }
            }
            else if(type=="E"){
                file>>r1;
                file>>r2;
                try{
                    p= new Ellipse(r1,r2);
                    cE++;
                    cout<<"El·lipse número "<<cE<<"."<<endl;
                    cout<<"L’àrea d’aquesta el·lipse és de "<<p->getArea()<<"."<<endl;
                    try{
                        cont->addEllipse(p);
                    }
                    catch(invalid_argument& e){
                        cout<<e.what()<<endl;
                    }
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
    vector<string> vec_options(5);
    int option;
    int c_cercle=0;
    int c_elipse=0;
    Ellipse *p;
    EllipseContainer *cont=new EllipseContainer();
    
    vec_options[0]="Sortir";
    vec_options[1]="Afegir figura";
    vec_options[2]="Glossari de figures";
    vec_options[3]="LLegir figures d'un fitxer";
    vec_options[4]="Suma d'àrees";
    
    do{
        cout<<"Hola, que vols fer?"<<endl;
        option=menu(vec_options);
        switch(option){
            case 0:cout<<"Adéu"<<endl;break;
            case 1:crearFigura(c_cercle,c_elipse,p,cont);break;
            case 2:mostrarGlosari(c_cercle,c_elipse);break;
            case 3:llegirFigures(c_cercle,c_elipse,p,cont);break;
            case 4:cout<<"La suma total d'àrees és: "<<cont->getAreas()<<endl;
        }
    }while(option!=0);
    
    vec_options.clear();
    vector<string>().swap(vec_options);
    delete cont;
    p = NULL;
    delete p;
    return 0;
}

/*Comentari: al netbeans em marca com error tot el que està relacionat
 amb la lectura d'un fitxer exterior, però no dona problemes a l'hora de compilar*/

/*a. Què ens permet fer l’herència que no podríem fer altrament?
 * Podem fer ús del polimorfisme, és a dir, podem declarar una variable Ellipse
 * i després utilitzar-la com a cercle o com a el·lipse, depenent del que sigui
 * necessari en cada moment.
 * 
 * b. Que passa si getArea() de la classe Ellipse no és virtual? Per què?
 * Si no és virtual podria ser que al tenir el punter de tipus Ellipse, si 
 * l'assignem a un cercle es crida el getArea de l'el·lipse.
 * Igualment, considero que tal i com està plantejat aquesta pràctica no té molt
 * de sentit diferenciar el mètode getArea de l'el·lipse i el cercle. Ens diu que 
 * el cercle es tracta d'una el·lipse en el cas que r1=r2. És a dir que l'expressió
 * de l'àrea és totalment compatible entre les dues figures. Per tant ni seria 
 * necessari tenir un mètode getArea a cercle, ja que podem utilitzar el de 
 * l'el·lipse sense cap mena de problema.
 * 
 * c. Per què els constructors i destructors els hem de cridar a les classes derivades i no a
la classe base?
 * Perquè és la classe més específica. Si per exemple a la classe derivada tinguéssim
 * un vector que no està en la base, si cridem al destructor de la base no s'eliminarà
 * aquest vector.
 * 
 * d. Es podria fer que getArea() fos un mètode de la classe pare “Ellipse”?
 * Sí, de fet nosaltes és com ho hem fet. Explicat els motius en la pregunta b.
 * 
 * e. Anomena els membres de dades definits en els teus programes i digues a quina
 * classe pertanyen. Explica les decisions de visibilitat de cadascun.
 * No entenc molt bé la pregunta. En l'exercici 6 he afegit en el main un punter
 * de tipus Ellipse, que després serà utilitzat a l'hora de crear cercles i ellipses.
 * D'aquesta manera utilitzem variables dinàmiques i no creem cada vegada una de 
 * nova, sinó que anem sobrecarregant. En el 7 hem fet el mateix amb el contenidor.
 * Els comptadors de cercles i ellipses passem l'adreça als mètodes d'afegir per 
 * tal de modificar el seu valor sense haver de retornar res.
 * Pel que fa la visibilitat dels atributs i mètodes de les classes cercle i ellipse,
 * inicialment tenien els radis privats i constructor, destructor i getArea publics.
 * Després, al fer l'herència, el cercle ja no necessitava cap atribut, ja que el 
 * seu radi era r1=r1. Hem passat doncs els radis de l'ellipse a protected.
 * 
 * f. L’iterador que recorre les figures, quant s’incrementa cada cop? Perquè?
 * L'iterador és un punter que apunta va apuntant a les caselles del vector. 
 * El vector guarda una serie de dades en adreces que van seguides a la memòria.
 * Per tant, quan l'iterador incrementa, el que fa és apuntar a la adreça següent, 
 * fins que arriba al final del vector.
 * 
 */

