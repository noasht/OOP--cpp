/* Assignment: 1 Question number 3
Author: Noa Shem Tov */

#ifndef HW1_MYNUMBERSTACK_MYNUMBERSTACKH_H
#define HW1_MYNUMBERSTACK_MYNUMBERSTACKH_H

#include "MyNumberH.h"

#define SIZE_DEFAULT 100
#define ZERO 0

class MyNumberStack {

private:
    int capacity;//the capacity of the stack
    int Top;//amount of values currently in the stack
    MyNumber ** ArrayOfPointers;//an array of MyNumber pointers
    static int InitiatorBuilder;//used to boot a constructor

    //functions
    MyNumber ** CreatStack()const;//create the stack, bring the address

public:
    MyNumberStack();//default constructor
    MyNumberStack(const int &capacity);// Parameterized constructor
    MyNumberStack(const MyNumberStack &StackX);//copy constructor
    ~MyNumberStack();//destructor
    int size()const {return this -> Top;}//returns stack size at the moment//inline
    bool isEmpty()const;//will return truth if the stack is empty false otherwise
    bool isFull()const;//return true if top == capacity, when the stack is full
    bool push(const MyNumber &ObjectMyNumX);//set the stack, add another object if the process succeed return true else false
    MyNumber * pop();//removes the object at the top of the stack from the stack, return the pointer to the object / null if the stack is empty
    MyNumber * top()const;//return method points to the object at the top of the stack without removing it from the stack.
};
#endif //HW1_MYNUMBERSTACK_MYNUMBERSTACKH_H
