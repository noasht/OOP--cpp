/* Assignment: 2
Author: Noa Shem Tov   */

#include <iostream>
using namespace std;
#include "MyNumber.h"

#define YES 'Y'
#define NO 'N'
#define TEN 10
#define ONE_CHAR '1'
#define ZERO_CHAR '0'
#define END_STRING '\0'

MyNumber::MyNumber()//default constructor
{
    this-> SizeArray_NumOfBinDig = ONE;//the size of the array is 1 -> 0 is also digit
    this-> BinaryNumber = new bool [ONE];//0 is one digit
    this-> BinaryNumber[ZERO] = false; // 0 = false
}//MyNumber
MyNumber::MyNumber(long Number)// Parameterized constructor
{
    CreateByNumber(Number);//if it's not default
}//MyNumber
void MyNumber::CreateByNumber(long Num)//creates the object by the received number
{
    if(Num < ZERO)
        Num *= NEG_ONE;//if the number is negative
    SizeArray_NumOfBinDig = ONE;//the minimum of size
    long tempNum = Num;//temp for calculation
    while (tempNum / TWO != ZERO)//counts how many times 2 appears in the current number
    {
        SizeArray_NumOfBinDig++;
        tempNum /= TWO;
    }//while
    BinaryNumber = new bool [SizeArray_NumOfBinDig];//the new array for the Num
    tempNum = Num;//for another calculation
    for (int i = SizeArray_NumOfBinDig - ONE; i >= ZERO ; --i)//calculation the remainder in the number that read from left to right
        // the last significant bit should appear at the end of the array
    {
        if(tempNum % TWO == ZERO)
            BinaryNumber[i] = false;//calculation the remainder
        else
            BinaryNumber[i] = true;
        tempNum /=TWO;
    }//for
}//CreateByNumber
MyNumber::MyNumber(const MyNumber &ObjectX)//copy constructor
{
    this ->SizeArray_NumOfBinDig = ObjectX.SizeArray_NumOfBinDig;//copy the size of the array
    this -> BinaryNumber = new bool [SizeArray_NumOfBinDig];//create array in the same size
    for (int i = ZERO; i <SizeArray_NumOfBinDig ; ++i)
        this -> BinaryNumber[i] = ObjectX.BinaryNumber[i];//copy every cell
}//MyNumber
MyNumber::~MyNumber()//destructor
{
    delete [] BinaryNumber;//delete the dynamic allocation
    BinaryNumber = nullptr;
}//~MyNumber
void MyNumber::BinaryPrint() const//print the binary value of the object
{
    //cout<<endl<<"the number "<<DecimalValueOfTheObject()<< " in binary is: "<< endl;//print the decimal number before //for myself
    for (int i = ZERO; i <SizeArray_NumOfBinDig ; ++i)
        cout<<BinaryNumber[i];//true == 1, false == 0
    cout<<endl;
}//BinaryPrint
void MyNumber::SetByNumber(long NumX)//setting the object by number
{
    delete [] BinaryNumber;//delete the dynamic allocation of the old number
    CreateByNumber(NumX);//create the new array for the new number
}//SetByNumber
void MyNumber::SetByObject(const MyNumber &ObjectX)//setting the object by object
{
    delete []  BinaryNumber;//delete the dynamic allocation of the old number
    this ->SizeArray_NumOfBinDig = ObjectX.SizeArray_NumOfBinDig;//the size of the new number
    this -> BinaryNumber = new bool [SizeArray_NumOfBinDig];//the creation of the new array for the new number
    for (int i = ZERO; i <SizeArray_NumOfBinDig ; ++i)
        this -> BinaryNumber[i] = ObjectX.BinaryNumber[i];//copy every cell
}//SetByObject
long MyNumber::DecimalValueOfTheObject()const//return the decimal value of the object
{
    long DecimalValue = ZERO;//sum of the number
    for (int i = ZERO; i < this->SizeArray_NumOfBinDig; ++i)
    {
        if (this->BinaryNumber[i])//only if is 1 is calculation if not it continue to the next cell
        {
            int power = this->SizeArray_NumOfBinDig - ONE - i;
            int temp = ONE;
            for (int j = ZERO;j < power; ++j)//the Calculation of power, the left cell == [0] is the most significant bit
                temp *= TWO;
            DecimalValue += temp;//add the result of each cell every iteration
        }//if
    }//for
    return DecimalValue;//return the number in decimal form
}//DecimalValueOfTheObject
bool MyNumber::AreTheseTwoObjectEquals(const MyNumber &ObjectX) const//check if the 2 objects the current == the received object
{
    if(this->SizeArray_NumOfBinDig != ObjectX.SizeArray_NumOfBinDig )//fist of all if the size are not equal return false
        return false;
    for (int i = ZERO; i < this ->SizeArray_NumOfBinDig ; ++i)
        if(this->BinaryNumber[i] != ObjectX.BinaryNumber[i])//every cell need to be equal, else false
            return false;
    return true;
}//AreTheseTwoObjectEquals
MyNumber MyNumber::SumOfObjects(const MyNumber &ObjectX) const //returns an object that is actually an addition of two objects
{
    long Number = this->DecimalValueOfTheObject() + ObjectX.DecimalValueOfTheObject();//to find out what is the number to do object for
    MyNumber SumOBJ (Number);//constructor for the new object
    return SumOBJ;//return the object
}//SumOfObjects
const MyNumber MyNumber::operator + (const MyNumber &addNumber)const
{
    return SumOfObjects(addNumber);//using function that already exist
}//operator +
const MyNumber MyNumber::operator * (const MyNumber & multiNumber)const
{
    long product = this->DecimalValueOfTheObject() * multiNumber.DecimalValueOfTheObject();//the value in decimal
    MyNumber ProductObject (product);//conversion constructor
    return ProductObject;//the neu object the Product
}//operator *
const MyNumber MyNumber::operator / (const MyNumber & divNumber)const
{
    long divNumOfObject = divNumber.DecimalValueOfTheObject();//the value in decimal
    if(divNumOfObject == ZERO)//check if is equal to 0
    {
        MyNumber quotient (ONE);
        return  quotient;//the object that equal to one
    }//if
    long quotient = this->DecimalValueOfTheObject() / divNumOfObject;//the Quotient of the objects
    MyNumber QuotientObject (quotient);//the new object conversion constructor
    return QuotientObject;
}//operator /
const MyNumber MyNumber::operator % (const MyNumber & remainderNumber) const
{
    long remNumOfObject = remainderNumber.DecimalValueOfTheObject();//the value in decimal
    if(remNumOfObject == ZERO)//check if is equal to zero
    {
        MyNumber quotient (ONE);//conversion constructor
        return quotient;//return object that equal to one
    }//if
    long quotient = this->DecimalValueOfTheObject() % remNumOfObject;//the value of the new object
    MyNumber QuotientObject (quotient);//conversion constructor
    return QuotientObject;
}//operator %
MyNumber& MyNumber::operator = (const MyNumber & ObjectToCopy)
{
    if(this != & ObjectToCopy)//only if is not the same object
        this->SetByObject(ObjectToCopy);
    return *this;
}
MyNumber& MyNumber::operator %= (const MyNumber & remainderNumber)
{
    (*this) = *this % remainderNumber;//using operator = and %
    return *this;
}//operator %=
MyNumber& MyNumber::operator /= (const MyNumber & divNumber)
{
    (*this) = *this / divNumber;//using operator = and /
    return *this;
}//operator /=
MyNumber& MyNumber::operator *= (const MyNumber & multiNumber)
{
    (*this) = *this * multiNumber;//using operator = and *
    return *this;
}//operator *=
MyNumber& MyNumber::operator += (const MyNumber & addNumber)
{
    (*this) = *this + addNumber;//using operator = and +
    return *this;
}//operator +=
MyNumber& MyNumber::operator ++ ()//prefix operator, first update and then send the new object
{
    long plusOne = this->DecimalValueOfTheObject() + ONE;
    this->SetByNumber(plusOne);
    return *this;
}//operator ++ pre
const MyNumber MyNumber::operator ++ (int)//postfix operator, first send the object and then update
{
    MyNumber postObject (this->DecimalValueOfTheObject());
    ++*this;
    return postObject;
}//operator ++ post
bool MyNumber::operator >= (const MyNumber & Number) const
{
    return (this->operator == (Number) || this->operator > (Number));
}//operator >=
bool MyNumber::operator <= (const MyNumber & Number) const
{
    return (!(this-> operator > (Number)));
}//operator <=
bool MyNumber::operator > (const MyNumber & Number) const
{
    if(this->DecimalValueOfTheObject() > Number.DecimalValueOfTheObject())
        return true;
    return false;
}//operator >
bool MyNumber::operator < (const MyNumber & Number) const
{
    if(this->DecimalValueOfTheObject() < Number.DecimalValueOfTheObject())
        return true;
    return false;
}//operator <
bool MyNumber::operator != (const MyNumber & Number) const
{
    return (!((*this) == (Number)));
}//operator !=
bool MyNumber::operator == (const MyNumber & Number) const
{
    return this->AreTheseTwoObjectEquals(Number);
}//operator ==
std::ostream &operator << (ostream &output, const MyNumber &Number)
{
    for (int i = ZERO; i <Number.SizeArray_NumOfBinDig ; ++i)
        output<<Number.BinaryNumber[i];//true == 1, false == 0
    return output;
}//operator <<
std::istream &operator >> (istream &input,MyNumber & MyNum)
{
    long BinNum;//number that the user type
    input>>BinNum;
    long num = BinNum;
    int counter = ZERO;//counter number Of digit's number
    char theNumIsBin = YES;//if the user type number that is not Binary
    while (num != ZERO && theNumIsBin == YES)
    {
        if(num % TEN != ONE &&  num % TEN != ZERO)//check if every digit equal to 1 or 0 if not the value of the object will be zero
            theNumIsBin = NO;
        else//it's a binary digit
        {
            counter++;
            num /= TEN;
        }//else
    }//while
    num = BinNum;
    if(theNumIsBin == YES && num != ZERO)
    {
        long DecimalValue = ZERO;//sum of the number
        for (int i = ZERO; i < counter; ++i)
        {
            if (num % TEN == ONE)//only if is 1 is calculation if not it continue to the next digit
            {
                int temp = ONE;
                for (int j = ZERO; j < i; ++j)//the Calculation of power, the left digit is the most significant bit
                    temp *= TWO;
                DecimalValue += temp;//add the result of each digit every iteration
            }//if
            num /= TEN;
        }
        MyNum.SetByNumber(DecimalValue);//set the object by the decimal value
    }
    else MyNum.SetByNumber(ZERO);//if the number wasn't Binary the value of the object will be 0
    return input;
}//operator >>
MyNumber::operator const int() const
{
    return (int)this->DecimalValueOfTheObject();//exist function
}//operator int
MyNumber::operator const char * ()const
{
    char * NumberBinString = new char [SizeArray_NumOfBinDig + ONE];//for the end sign
    for(int i = ZERO; i < SizeArray_NumOfBinDig ; i++)
    {
        if (BinaryNumber[i])//if the cell is true
            NumberBinString[i] = ONE_CHAR;//'1'
        else
            NumberBinString[i] = ZERO_CHAR;//'0'
    }//for
    NumberBinString [SizeArray_NumOfBinDig] = END_STRING;// add the end sign of the string
    return NumberBinString; // return the string
}//operator char *


