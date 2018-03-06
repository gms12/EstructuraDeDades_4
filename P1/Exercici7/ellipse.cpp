/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Ellipse.h"
#include <math.h>
#include <stdexcept>
#include <iostream>

using namespace std;
Ellipse::Ellipse(float r1,float r2){
    if(r1<=0 || r2<=0)throw invalid_argument("Atenció: aquests valors no són acceptats");
    else {
        this->r1=r1;
        this->r2=r2;
        cout<<"Sóc el constructor de l'El·lipse"<<endl;
    }
}
Ellipse::~Ellipse(){
    cout<<"Eliminant El·lipse."<<endl;
}
float Ellipse::getArea(){
    return M_PI*r1*r2;
}