/* Assignment: 4 Question 2
Author: Noa Shem Tov
 */

#include "Cylinder.h"

Cylinder::Cylinder(float height,float radius,char * color): Circle(radius,color)
{
    this->height = height;
    SumVolume += this->Volume();
}//constructor
Cylinder::Cylinder (const Cylinder& ObToCopy): Circle(ObToCopy)
{
    this->height = ObToCopy.height;
    SumVolume += this->Volume();
}//copy constructor
float Cylinder::Area()const
{
    return TWO * PI * this->radius * (this->radius + this->height);
}//Area
float Cylinder::Volume()const
{
    return PI * this->radius * this->radius * this->height;
}//Volume
void Cylinder::print(ostream &output)const
{
    output<<"Cylinder o"<<endl;
    Shape::print(output);
    output<<"\tThe radius is: "<<radius<<endl;
    output<<"\tThe height is: "<<height<<endl;
    output<<"\tThe Area of the Cylinder is: "<<Area()<<endl;
    output<<"\tThe Volume of the Cylinder is: "<<Volume()<<endl;
}//Print