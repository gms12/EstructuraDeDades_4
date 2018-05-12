/* 
 * File:   main.cpp
 * Author: Gabriel Marín i Martí Pedemonte
 *
 * Created on 27 de abril de 2018, 13:16
 */

#include <cstdlib>
#include <ctime>
#include <vector>
#include "BalancedBSTMovieFinder.h"

using namespace std;

//metode per a mostrar el menu
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

//metode per a realitzar la primera opcio del menu
void initialize(BalancedBSTMovieFinder* mF){
    //PART 1-----------------------------------
    /*
     * Aqui el que fem es borrar l'arbre i inicialitzar-ne un de nou
     * Si no fessim aixo, aleshores al clicar l'opció 1 tindriem un arbre més
     * gran amb els elements repetits, i no volem aixo. Aixi que el millor es
     * esborrar l'arbre anterior i fer-ne un de nou amb els elements que
     * l'usuari desitgi
     * 
     */
    delete mF;
    mF = new BalancedBSTMovieFinder();
    
    string resposta, fileName;
    cout<<"Quin fitxer vols (P/G)? ";
    cin>>resposta;
    while(resposta != "P" && resposta != "G" && resposta != "p" && resposta != "g"){
        cout<<"A veure, no és tan difícil. Quin fitxer vols (P/G)? ";
        cin>>resposta;
    }
    if(resposta == "P" || resposta == "p") fileName = "movie_rating_small.txt";
    else fileName = "movie_rating.txt";
    
    clock_t initialTime = clock();
    //cout<<t<<endl;
    mF->appendMovies(fileName);
    clock_t finalTime = clock();
    //cout<<t<<endl;
    cout<<"It took "<< ((float)(finalTime-initialTime))/(CLOCKS_PER_SEC)<<" seconds."<<endl;
    cout<<"Height: "<<mF->getTree()->getHeight()<<endl;

}
//metode per a realitzar la 3a opcio del menu
void cerca(BalancedBSTMovieFinder* mF){
    //PART 3-----------------------------------
    clock_t initialTime = clock();
    ifstream myFile;
    myFile.open("cercaPelicules.txt");
    int isInTree = 0;
    string line;
    
    if(!myFile.is_open()){
        cout<< "Unable to open file."<<endl;
    }else{
        while( getline((myFile), line) ){
            if( mF->searchMovie( atoi(line.c_str()) ) ) isInTree++;
        }
    }
    clock_t finalTime = clock();
    cout<<"It took "<< ((float)(finalTime-initialTime))/(CLOCKS_PER_SEC)<<" seconds to search the whole tree."<<endl;
    cout<<"There are "<< isInTree <<" movies in the tree."<<endl;
}
/*
 * Main
 */
int main(int argc, char** argv) {
    
    vector<string> vec_options(5);
    int option;
    string resposta, fileName;
    clock_t initialTime, finalTime;

    vec_options[0]="Llegir fitxer i inicialitzar arbre";
    vec_options[1]="Mostrar l’arbre segons l’ID en ordre creixent";
    vec_options[2]="Llegir el fitxer cercaPelicules.txt i mostrar nºelements";
    vec_options[3]="Visualitzar per pantalla la profunditat de l'arbre";
    vec_options[4]="Sortir";
    
    BalancedBSTMovieFinder* mF = new BalancedBSTMovieFinder();
    do{
        cout<<"Que vols fer?"<<endl;
        option=menu(vec_options);
        switch(option){
            case 0:
                delete mF;
                mF = new BalancedBSTMovieFinder();

                
                cout<<"Quin fitxer vols (P/G)? ";
                cin>>resposta;
                while(resposta != "P" && resposta != "G" && resposta != "p" && resposta != "g"){
                    cout<<"A veure, no és tan difícil. Quin fitxer vols (P/G)? ";
                    cin>>resposta;
                }
                if(resposta == "P" || resposta == "p") fileName = "movie_rating_small.txt";
                else fileName = "movie_rating.txt";

                initialTime = clock();
                //cout<<t<<endl;
                mF->appendMovies(fileName);
                finalTime = clock();
                //cout<<t<<endl;
                cout<<"It took "<< ((float)(finalTime-initialTime))/(CLOCKS_PER_SEC)<<" seconds."<<endl;
                cout<<"Height: "<<mF->getTree()->getHeight()<<endl;
                break;
            case 1:
                //PART 2-----------------------------------
                mF->printAscendingOrder();
                break;
            case 2:
                cerca(mF);
                break;
            case 3:
                //PART 4-----------------------------------
                cout<<"Depth: "<< mF->getTree()->getHeight()<<endl;
                break;
            case 4:
                cout<<"Adéu!"<<endl;
               
        }
    }while(option!=4);
    vec_options.clear();
    vector<string>().swap(vec_options);
    delete mF;
    
    //PROVES:
    //---------------
    /*
    BSTMovieFinder* mF = new BSTMovieFinder();
    mF->appendMovies("input");
    mF->getTree()->printPreorder();
    mF->insertMovie(56789, "Harry", 3.4567);
    mF->getTree()->printPreorder();
    Movie m = mF->findMovie(8923);
    cout<<m.toString()<<endl;
    cout<<mF->findRatingMovie(8923)<<endl;
    cout<<mF->showMovie(8923)<<endl;
    delete mF;
    */
    //-------------
    return 0;
}