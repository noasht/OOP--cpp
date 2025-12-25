/* Assignment: 4 Question 2
Author: Noa Shem Tov
 */

#include "Circle.h"

Circle::Circle(float radius,char * color): Shape(color)
{
    if(radius < ONE)//can't be negative
        this->radius = ONE;
    else this->radius = radius;
}//constructor
Circle::Circle(const Circle& ObToCopy): Shape(ObToCopy)
{
    if(ObToCopy.radius < ONE)//can't be negative
        this->radius = ONE;
    else this->radius = ObToCopy.radius;
}//copy constructor
float Circle::Area()const
{
    return (float)PI * radius * radius;
}//Area
void Circle::print(ostream &output)const
{
    output<<"Circle o"<<endl;
    Shape::print(output);
    output<<"\tThe radius is: "<<radius<<endl;
    output<<"\tThe Area of the circle is: "<<Area()<<endl;
}//print