/* Assignment: 4 Question 2
Author: Noa Shem Tov
 */

#ifndef SHAPE_CPP_CIRCLE_H
#define SHAPE_CPP_CIRCLE_H

#include "Shape.h"

class Circle : public Shape{

protected:
    float radius;

public:
    Circle(float radius,char * color);//constructor
    Circle(const Circle& ObToCopy);//copy constructor
    float Area()const;//calculate the area
    char *GetShape()const{return "Circle";}//for the print function by shapes
    void print(ostream &output)const;//print the object
};
#endif //SHAPE_CPP_CIRCLE_H
