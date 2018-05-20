/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EllipseContainer.h
 * Author: Gabriel
 *
 * Created on 4 de marzo de 2018, 10:55
 */

#ifndef ELLIPSECONTAINER_H
#define ELLIPSECONTAINER_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
#include <vector>
#include "Ellipse.h"
#include "circle.h"
using namespace std;
class EllipseContainer{
private:
    vector<Ellipse*> v;
public:
    EllipseContainer();
    ~EllipseContainer();
    void addEllipse (Ellipse *);
    float getAreas();
};

#endif /* ELLIPSECONTAINER_H */

