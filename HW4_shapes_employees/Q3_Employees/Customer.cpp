/* Assignment: 4 Question 3
Author: Noa Shem Tov
 */

#include "Customer.h"

Customer::Customer(float * PayList, int sizeOfPayList, char * Name, long ID) : Person(Name , ID)
{
    if(sizeOfPayList > ZERO )
    {
        this->PayList = new float[sizeOfPayList];
        for (int i = ZERO; i < sizeOfPayList; ++i)
            this->PayList[i] = PayList[i];
        this->sizeOfPayList = sizeOfPayList;
    }//if
    else
    {
        this->PayList = nullptr;
        this->sizeOfPayList = ZERO;
    }//else
}//constructor
Customer::Customer(const Customer & EmployeeToCopy) : Person(EmployeeToCopy)
{
    if (EmployeeToCopy.sizeOfPayList > ZERO)
    {
        this->PayList = new float[EmployeeToCopy.sizeOfPayList];
        for (int i = ZERO; i < sizeOfPayList; ++i)
            this->PayList[i] = EmployeeToCopy.PayList[i];
        this->sizeOfPayList = EmployeeToCopy.sizeOfPayList;
    }//if
    else
    {
        this->PayList = nullptr;
        this->sizeOfPayList = ZERO;
    }//else
}//copy constructor
Customer::~Customer()
{
    delete [] PayList;
    this->PayList = nullptr;
}//destructor
void Customer::print(ostream &output)const
{
    output<<"Customer"<<endl;
    output << "The Customer's name is :\n"<<this->Name<<endl;
    output<< "The Customer's ID :\n" << this->ID<<endl;
    if(sizeOfPayList != ZERO)
    {
        output << "The Customer's PayLIST  " << endl;
        for (int i = ZERO; i < sizeOfPayList; i++)
            output << "Pay number " << i + ONE << ": "<<PayList[i]<<endl;
        cout<<endl;
    }
    else cout<<"There is no PayList"<<endl<<endl;
}//print
void Customer::Buy(float pay)
{
    float * temp = new float [sizeOfPayList + ONE];
    for (int i = 0; i < sizeOfPayList; ++i)
        temp[i] = PayList[i];
    temp[sizeOfPayList] = pay;
    delete [] PayList;
    PayList = temp;
    sizeOfPayList++;
}//Buy