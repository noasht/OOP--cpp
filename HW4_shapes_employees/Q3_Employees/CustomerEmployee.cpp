/* Assignment: 4 Question 3
Author: Noa Shem Tov
 */

#include "CustomerEmployee.h"
CustomerEmployee::CustomerEmployee(float salary,float * PayList, int sizeOfPayList, char * Name, long ID)
: Person(Name,ID), Employee(salary,Name,ID) , Customer(PayList,ZERO,Name,ID)
{
    if(sizeOfPayList > ZERO)
    {
        this->PayList = new float [sizeOfPayList];
        for (int i = 0; i < sizeOfPayList; ++i)
            this->PayList[i] = PayList[i] * DISCOUNT;
        this->sizeOfPayList = sizeOfPayList;
    }//if
}//constructor
CustomerEmployee::CustomerEmployee(const CustomerEmployee & object):Person(object), Employee(object) , Customer(object){;}
void CustomerEmployee::print(ostream &output)const
{
    output<<"Customer & Employee"<<endl;
    output << "The Customer / Employee name is :\n"<<this->Name<<endl;
    output<< "The Customer / Employee ID :\n"<< this->ID<<endl;
    if(sizeOfPayList != ZERO) {
        output << "As a Customer the PayLIST is" << endl;
        for (int i = ZERO; i < sizeOfPayList; i++)
            output << "Pay number " << i + ONE << ": "<<PayList[i]<<endl;
    }
    else cout<<"There is no PayList"<<endl;
    output<<"As a Employee, the salary is "<<salary<<endl<<endl;
}//CustomerEmployee
void CustomerEmployee::Buy(float pay)
{
    float *temp = new float[sizeOfPayList + ONE];
    for (int i = 0; i < sizeOfPayList; ++i)
        temp[i] = PayList[i];
    temp[sizeOfPayList] = (float )(pay * DISCOUNT);//for employee there is a discount
    delete[] PayList;//delete the prev list
    PayList = temp;//get the address of the new list
    sizeOfPayList++;//the size get bigger in 1
}//Buy