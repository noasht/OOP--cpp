/* Assignment: 1 Question number 3
Author: Noa Shem Tov   */

#include "MyNumberStackH.h"
#define THREE  3
#define FOUR 4

int MyNumberStack::InitiatorBuilder = SIZE_DEFAULT;

int main()//This is just a test
{
    int inPut;//
    MyNumberStack x;//default constructor
    cout << "Please enter integer number for the capacity for stack y" << endl;
    cin >> inPut;
    MyNumberStack y(inPut);//constructor by parameter
    MyNumberStack w(THREE);//capacity of w is 4
    MyNumber a(ONE);// 1
    MyNumber b(FOUR);//100
    w.push(a);//push object a to stack w
    w.push(b);//push object b to stack w
    MyNumberStack z = w;//copy constructor
    MyNumber c(TWO);//create object MyNumber  == 10
    MyNumber d(THREE);//create object MyNumber  = 11
    z.push(c);//push to z stack the object a
    if (z.push(d))//push to z stack the object b
        cout << "It succeeded, " << endl;
    else
    {
        cout<<"Failed, can't push to stack z"<<endl;
        if(z.isFull())//YES
            cout<<"Z is full stack"<<endl;
    }
    cout<<"The amount of the objects in y stack is: "<<y.size()<<endl;
    cout<<"The amount of the objects in z stack is: "<<z.size()<<endl;
    if(y.isFull())//no
        cout<<"Y is full stack"<<endl;
    else
        cout<<"Y is empty"<<endl;
    x.push(*z.pop());//the object that pop from z stack transfer to x stack * because pop return pointer but push received object not pointer
    cout<<"The amount of the objects in x stack is: "<<x.size()<<endl;
    if(!y.isEmpty())//yes
        cout<<"Y is full stack"<<endl;
    else
        cout<<"Y is empty"<<endl;
    y.push(*x.top());
    cout<<"The amount of the objects in y stack is: "<<y.size()<<endl;
    return 0;//~destructors
}
