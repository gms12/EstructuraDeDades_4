/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "circle.h"
#include <math.h>
#include <stdexcept>


using namespace std;

Circle::Circle(float r){
    if(r>0) radi=r;
    else throw invalid_argument("Atenció: aquest valor no és acceptat");
}
float Circle::getArea(){
    return M_PI*radi*radi;
}