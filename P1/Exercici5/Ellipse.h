/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.h
 * Author: Gabriel
 *
 * Created on 27 de febrero de 2018, 10:51
 */

#ifndef ELLIPSE_H
#define ELLIPSE_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
class Ellipse{
private:
    float r1;
    float r2;
public:
    Ellipse(float,float);
    virtual float getArea(void);
};
#endif /* ELLIPSE_H */

