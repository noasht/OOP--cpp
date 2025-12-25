/* Assignment: 4 Question 2
Author: Noa Shem Tov
 */

#ifndef MAIN_CPP_CUBOID_H
#define MAIN_CPP_CUBOID_H

#include "Rectangle.h"

class Cuboid : public Rectangle {

private:
    float height;
public:
    Cuboid(float height,float length, float width,char * color);
    Cuboid(const Cuboid& ObToCopy);
    float Area()const;
    virtual float Volume()const;
    char *GetShape()const{return "Cuboid";}
    void print(ostream &output)const;
};


#endif //MAIN_CPP_CUBOID_H
