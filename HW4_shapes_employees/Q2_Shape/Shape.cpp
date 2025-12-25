/* Assignment: 4 Question 2
Author: Noa Shem Tov
 */

#include "Shape.h"

float Shape::SumVolume = ZERO;

Shape::Shape(char *color)
{
    if(color != nullptr)
        this->color = MadeStr(color);
    else
        this->color = nullptr;
}//constructor
char * Shape::MadeStr(char *stringColor) const
{
    int sizeColor = (int)(strlen(stringColor)) + ONE;
    char * pointer = new char [sizeColor];
    strcpy(pointer,stringColor);
    return pointer;
}//MadeStr
Shape::Shape(const Shape& CopyOB)
{
    deleteOb();
    this->color = MadeStr(CopyOB.color);
}//copy constructor
Shape::~Shape()
{
    deleteOb();
}//destructor
void Shape::print(ostream &output)const
{
    if(this->color != nullptr)
        output <<"\tThe color is: "<< color<<endl;
}//print
void Shape::deleteOb()
{
    delete [] color;
    color = nullptr;
}//delete
ostream &operator << (ostream &output, const Shape& shape)
{
    shape.print(output);
    return output;
}//print <<
