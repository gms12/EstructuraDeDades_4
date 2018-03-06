/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "circle.h"
#include "Ellipse.h"
#include <math.h>
#include <iostream>
#include <stdexcept>


using namespace std;

Circle::Circle(float r):Ellipse(r,r){
    cout<<"Sóc el constructor del Cercle"<<endl;
}
Circle::~Circle(){
    cout<<"Eliminant Cercle."<<endl;
}
float Circle::getArea(){
    return M_PI*r1*r1;
}