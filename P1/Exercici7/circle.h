/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   circle.h
 * Author: Gabriel
 *
 * Created on 20 de febrero de 2018, 9:44
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
#include "Ellipse.h"
class Circle: public Ellipse{
public:
    Circle(float);
    ~Circle();
    float getArea(void);
};
#endif /* CIRCLE_H */



