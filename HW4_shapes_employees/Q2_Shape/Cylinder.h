/* Assignment: 4 Question 2
Author: Noa Shem Tov
 */

#ifndef SHAPE_CPP_CYLINDER_H
#define SHAPE_CPP_CYLINDER_H

#include "Circle.h"

class Cylinder : public Circle{

private:
    float height;

public:
    Cylinder(float height,float radius,char * color);//constructor
    Cylinder (const Cylinder& ObToCopy);//copy constructor
    float Area()const;//calculate the area
    virtual float Volume()const;//calculate the Volume
    char *GetShape()const{return "Cylinder";}//for the print by shape function
    void print(ostream &output)const;//print the object
};
#endif //SHAPE_CPP_CYLINDER_H
