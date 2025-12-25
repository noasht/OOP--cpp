/* Assignment: 1 Question number 2
Author: Noa Shem Tov   */
#include "MyNumberH.h"

MyNumber::MyNumber()//default constructor
{
    this-> SizeArray_NumOfBinDig = ONE;//the size of the array is 1 -> 0 is also digit
    this-> BinaryNumber = new bool [ONE];//0 is one digit
    this-> BinaryNumber[ZERO] = false; // 0 = false
}//MyNumber
MyNumber::MyNumber(long Number)// Parameterized constructor
{
    if(Number == ZERO)//if the number == 0, its like default constructor
        MyNumber();
    else CreateByNumber(Number);//if it's not default
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
        BinaryNumber[i] = tempNum % TWO;//calculation the remainder
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
    delete []  this ->BinaryNumber;//delete the dynamic allocation of the old number
    CreateByNumber(NumX);//create the new array for the new number
}//SetByNumber
void MyNumber::SetByObject(const MyNumber &ObjectX)//setting the object by object
{
    delete []  this ->BinaryNumber;//delete the dynamic allocation of the old number
    this ->SizeArray_NumOfBinDig = ObjectX.SizeArray_NumOfBinDig;//the size of the new number
    this -> BinaryNumber = new bool [SizeArray_NumOfBinDig];//the creation of the new array for the new number
    for (int i = ZERO; i <SizeArray_NumOfBinDig ; ++i)
        this -> BinaryNumber[i] = ObjectX.BinaryNumber[i];//copy every cell
}//SetByObject
long MyNumber::DecimalValueOfTheObject()const//return the decimal value of the object
{
    long DecimalValue = ZERO;//sum of the number
    for (int i = ZERO; i < this->SizeArray_NumOfBinDig; ++i)
        if(BinaryNumber[i])//only if is 1 is calculation if not it continue to the next cell
        {
            int power =  this ->SizeArray_NumOfBinDig - ONE- i;
            int temp = ONE;
            for (int j = ZERO; j < power; ++j)//the Calculation of power, the left cell == [0] is the most significant bit
                temp *=TWO;
            DecimalValue+=temp;//add the result of each cell every iteration
        }//if
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