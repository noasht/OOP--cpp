/* Assignment: 1 Question number 3
Author: Noa Shem Tov */

#ifndef HW1_MYNUMBERSTACK_MYNUMBERH_H
#define HW1_MYNUMBERSTACK_MYNUMBERH_H
#include <iostream>
using namespace std;

#define ZERO 0
#define ONE 1
#define NEG_ONE (-1)
#define TWO 2

class MyNumber {

private:
    int SizeArray_NumOfBinDig;//the size if the array == the sum of the digit in binary form
    bool * BinaryNumber;//array that include true for 1/false for 0

    void CreateByNumber(long Num);//creates the object by the received number
public:
    MyNumber();//default constructor
    MyNumber(long Number);//constructor by parameter
    MyNumber(const MyNumber &ObjectX);//copy constructor
    ~MyNumber();//destructor
    void BinaryPrint() const ;//print the binary value of the object
    void SetByNumber(long NumX);//setting the object by number
    void SetByObject(const MyNumber &ObjectX);//setting the object by object
    bool AreTheseTwoObjectEquals(const MyNumber &ObjectX) const;//check if the 2 objects the current == the received object
    MyNumber SumOfObjects(const MyNumber &ObjectX) const;//returns an object that is actually an addition of two objects
    long DecimalValueOfTheObject()const;//return the decimal value of the object
};
#endif //HW1_MYNUMBERSTACK_MYNUMBERH_H
