/* Assignment: 4 Question 2
Author: Noa Shem Tov
 */

#ifndef MAIN_CPP_RING_H
#define MAIN_CPP_RING_H

#include "Circle.h"

class Ring : public Circle{

private:
    float radius1;

public:
    Ring(float radius, float radius1,char * color);//constructor
    Ring(const Ring& ObToCopy);//copy constructor
    float Area()const;//calculate the area
    char *GetShape()const{return "Ring";}//for the print by shape function
    void print(ostream &output)const;//print the object
};
#endif //MAIN_CPP_RING_H
