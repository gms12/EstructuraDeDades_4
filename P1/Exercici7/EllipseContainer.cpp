/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "EllipseContainer.h"

#include <vector>
#include <iostream>
#include <stdexcept>

EllipseContainer::EllipseContainer(){
    vector<Ellipse*> tv;
    this->v=tv;
}
EllipseContainer::~EllipseContainer(){
    vector<Ellipse *>::iterator it;
    for (it = this->v.begin() ; it != this->v.end(); ++it){
        if (dynamic_cast<Circle*>(*it))delete (Circle *)(*it);
        else delete *it;
    }
    v.clear();
    vector<Ellipse *>().swap(v);
    cout<<"Eliminant Contenidor."<<endl;
    
}
void EllipseContainer::addEllipse(Ellipse* a){
    if(v.size()<10)v.push_back(a);
    else throw invalid_argument("Ja tens 10 figures guardades. No en pots afegir més.");
}
float EllipseContainer::getAreas(){
    float suma=0;
    vector<Ellipse *>::iterator it;
    for (it=this->v.begin() ; it != this->v.end(); ++it){
        suma+=(*it)->getArea();
    }
    return suma;
}
