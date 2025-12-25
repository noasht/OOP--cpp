/* Assignment: 4 Question 2
Author: Noa Shem Tov
 */

#include "Rectangle.h"

Rectangle::Rectangle(float length, float width,char * color) : Shape(color)
{
    if(length < ONE)//must be positive
        this->length = ONE;
    else this->length = length;
    if(width < ONE)//must be positive
        this->width = ONE;
    else this->width = width;
}//constructor
Rectangle::Rectangle(const Rectangle& ObToCopy) : Shape(ObToCopy)
{
    if(ObToCopy.length < ONE)//must be positive
        this->length = ONE;
    else this->length = ObToCopy.length;
    if(ObToCopy.width < ONE)//must be positive
        this->width = ONE;
    else this->width = ObToCopy.width;
}//copy constructor
float Rectangle::Area()const
{
    return length*width;
}//Area
void Rectangle::print(ostream &output)const
{
    output<<"Rectangle [] "<<endl;
    Shape::print(output);
    output<<"\tThe length is: "<<length<<endl;
    output<<"\tThe width is: "<<width<<endl;
    output<<"\tThe Area of the Rectangle is: "<<Area()<<endl;
}//print