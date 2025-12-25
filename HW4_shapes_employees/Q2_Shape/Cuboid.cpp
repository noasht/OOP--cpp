/* Assignment: 4 Question 2
Author: Noa Shem Tov
 */

#include "Cuboid.h"

Cuboid::Cuboid(float height,float length, float width,char * color) : Rectangle(length, width, color)
{
    this->height = height;
    SumVolume += this->height * this->width * this->length;
}//constructor
Cuboid::Cuboid(const Cuboid& ObToCopy) : Rectangle(ObToCopy)
{
    this->height = ObToCopy.height;
    SumVolume += this->height * this->width * this->length;
}//copy constructor
float Cuboid::Area()const
{
    return TWO * (this->length * this->width + this->length * this->height + this->height * this->width);
}//Area
float Cuboid::Volume()const
{
    return this->height * this->width * this->length;
}//Volume
void Cuboid::print(ostream &output)const
{
    output<<"Cuboid [] "<<endl;
    Shape::print(output);
    output<<"\tThe length is: "<<length<<endl;
    output<<"\tThe width is: "<<width<<endl;
    output<<"\tThe height is: "<<height<<endl;
    output<<"\tThe Area of the Cuboid is: "<<Area()<<endl;
    output<<"\tThe Volume of the Cuboid is: "<<Volume()<<endl;
}//print