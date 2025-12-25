/* Assignment: 4 Question 2
Author: Noa Shem Tov
 */

#include "Ring.h"

Ring::Ring(float radius, float radius1,char * color) : Circle (radius , color)
{
    if(radius1 < ONE)//can't be negative
        this->radius1 = ONE;
    else this->radius1 = radius1;
}//constructor
Ring::Ring(const Ring& ObToCopy) : Circle(ObToCopy)
{
    if(ObToCopy.radius1 < ONE)//can't be negative
        this->radius1 = ONE;
    else this->radius1 = ObToCopy.radius1;
}//copy constructor
float Ring::Area()const
{
    return PI * (this->radius * this->radius - this->radius1 * this->radius1);
}//Area
void Ring::print(ostream &output)const
{
    output<<"Ring o"<<endl;
    Shape::print(output);
    output<<"\tThe radius is: "<<radius<<endl;
    output<<"\tThe radius1 is: "<<radius1<<endl;
    output<<"\tThe Area of the Ring is: "<<Area()<<endl;
}//Print