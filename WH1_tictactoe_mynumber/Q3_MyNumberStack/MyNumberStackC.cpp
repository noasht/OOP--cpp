/* Assignment: 1 Question number 3
Author: Noa Shem Tov */

#include "MyNumberStackH.h"

MyNumberStack::MyNumberStack()//default constructor
{
    this ->capacity = InitiatorBuilder;//default size = 100
    this ->Top = ZERO;//there is no objects in the stack in the beginning
    this ->ArrayOfPointers = CreatStack();//create the array of MyNumber pointers
}//MyNumberStack
MyNumber ** MyNumberStack::CreatStack()const//create the stack in the same value that in the capacity
{
    MyNumber ** tempOfMyNumSt = new MyNumber *[this -> capacity];//dynamic memory allocation
    for (int i = ZERO; i < this->capacity ; ++i)
        tempOfMyNumSt[i] = nullptr;//Initialize pointers
    return tempOfMyNumSt;
}//CreatStack
MyNumberStack::MyNumberStack(const int &capacity)// Parameterized constructor
{
    if(capacity <= ZERO )//if the input is not valid it will be default stack
    {
        this ->capacity = InitiatorBuilder;//default size = 100
        this ->Top = ZERO;//there is no objects in the stack in the beginning
        this ->ArrayOfPointers = CreatStack();//create the array of MyNumber pointers
    }
    else
    {
        this->capacity = capacity;//the wanted size
        this->Top = ZERO;//the amount of the objects at the creation is 0
        this->ArrayOfPointers = CreatStack();//create the array of MyNumber pointers
    }
}//MyNumberStack
MyNumberStack::MyNumberStack(const MyNumberStack &StackX)//copy constructor
{
    this->capacity = StackX.capacity;//copy the size of the stack
    this->Top = StackX.Top;//copy the amount of the objects in the stack
    this->ArrayOfPointers = CreatStack();//create the array of MyNumber pointers
    for (int i = ZERO; i < this->Top; ++i)
        this->ArrayOfPointers[i] = new MyNumber (StackX.ArrayOfPointers[i]->DecimalValueOfTheObject());//the pointer to the object, create copy = the same value
}//MyNumberStack
MyNumberStack::~MyNumberStack() //destructor
{
    for (int i = ZERO; i < this->Top; ++i)
        delete this->ArrayOfPointers[i];//delete the object
    delete [] this -> ArrayOfPointers;//delete the array
    this -> ArrayOfPointers = nullptr;
}//~MyNumberStack
bool MyNumberStack::isEmpty()const//will return truth if the stack is empty false otherwise
{
    if(this ->Top == ZERO)//no object in the stack
        return true;
    return false;
}//isEmpty
bool MyNumberStack::isFull()const//return true if top >= capacity, when the stack is full
{
    if(this ->Top >= this ->capacity)
        return true;
    return false;
}//isFull
bool MyNumberStack::push(const MyNumber &ObjectMyNumX)//set the stack, add another object if the process succeed return true else, false
{
    if(this ->Top >= this ->capacity )//the stack is full cant add another object to the stack
        return false;
    this->ArrayOfPointers[this ->Top] = new MyNumber (ObjectMyNumX.DecimalValueOfTheObject());//the pointer to the object, create copy = the same value
    this -> Top++;//another object add to the stack the amount increase in 1
    return true;
}//Push
MyNumber * MyNumberStack::pop()
{
    if (this -> Top == ZERO)//no object to remove from the stack
        return nullptr;
    this ->Top --;//decrease the amount in 1
    MyNumber * Temp = this -> ArrayOfPointers[this -> Top];//create another pointer to hold the object,
    this -> ArrayOfPointers[this -> Top] = nullptr;//remove from the stack
    return Temp;
}//Pop
MyNumber * MyNumberStack::top()const//return method points to the object at the top of the stack without removing it from the stack.
{
    if(this ->Top == ZERO)
        return nullptr;
    return this ->ArrayOfPointers[this-> Top - ONE];
}//Top
