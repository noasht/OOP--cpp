/* Assignment: 4 Question 2
Author: Noa Shem Tov
 */

#ifndef SHAPE_CPP_RECTANGLE_H
#define SHAPE_CPP_RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {

protected:
   float length;
   float width;

public:
    Rectangle(float length, float width,char * color);//constructor
    Rectangle(const Rectangle& ObToCopy);//copy constructor
    float Area()const;//calculate the area
    char *GetShape()const{return "Rectangle";}//for the print by shape function
    void print(ostream &output)const;//print the object
};
#endif //SHAPE_CPP_RECTANGLE_H
