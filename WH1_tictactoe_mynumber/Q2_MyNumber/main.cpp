/* Assignment: 1 Question number 2
Author: Noa Shem Tov   */

#include "MyNumber.h"
#define TWENTY_FIVE 25
#define THIRTY 30
#define FIVE 5

int main()
{
    MyNumber x(TWENTY_FIVE);//25
    MyNumber y(THIRTY);//30
    MyNumber a;//0
    MyNumber z = x.SumOfObjects(y);//55
    x.SetByObject(a);//0
    a.SetByObject(y);//30
    y.SetByNumber(FIVE);//5
    MyNumber b = y.SumOfObjects(y);//10
    MyNumber c = b;//10
    x.SetByNumber(FIVE);//5
    b.SetByNumber(ONE);//1
    if(x.AreTheseTwoObjectEquals(y))
        cout<<"x and y are equal"<<endl;
    else  cout<<"x and y not! equal"<<endl;
    if(b.AreTheseTwoObjectEquals(y))
        cout<<"b and y are equal"<<endl;
    else  cout<<"b and y not! equal"<<endl;
     z.BinaryPrint();//110111
     cout<< "is "<< z.DecimalValueOfTheObject()<< endl;//55
    a.BinaryPrint();//11110
    cout<< "is "<< a.DecimalValueOfTheObject()<< endl;//30
    b.BinaryPrint();//1
    cout<< "is "<< b.DecimalValueOfTheObject()<< endl;//1
    c.BinaryPrint();//1010
    cout<< "is "<< c.DecimalValueOfTheObject()<< endl;//10
    x.BinaryPrint();//101
    cout<< "is "<< x.DecimalValueOfTheObject()<< endl;//5
    y.BinaryPrint();//101
    cout<< "is "<< y.DecimalValueOfTheObject()<< endl;//5
    return 0;
}
