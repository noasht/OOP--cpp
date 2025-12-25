/* Assignment: 4 Question 2
Author: Noa Shem Tov
 */

#ifndef HW4Q2_SHAPE_H
#define HW4Q2_SHAPE_H

#include <iostream>
#include <cstring>

#define PI 3.141
#define ONE 1
#define TWO 2
#define ZERO 0

using namespace std;

class Shape{

protected:
    char* color;
    static float SumVolume;

private:
    char * MadeStr(char * stringColor)const;//return the string
    void deleteOb();//delete the string

public:
    Shape(char *color);//constructor
    Shape(const Shape& CopyOB);//copy constructor
    ~Shape();//destructor
    friend ostream &operator << (ostream &output, const Shape& shape);//print function
    virtual void print(ostream &output)const;//print function which is virtual
    virtual float Area() const = 0;//calculate the area
    virtual char * GetShape()const = 0;//for the function print by shape
    char * GetColor()const{return this->color;}//get the color of the object
    static float GetVolume() {return SumVolume;}//get the volume
};
#endif //HW4Q2_SHAPE_H