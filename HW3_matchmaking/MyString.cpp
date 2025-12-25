/* Assignment: 3
Author: Noa Shem Tov, ID: 207000134  */

//#include "stdlib.h"
#include "MyString.h"

MyString::MyString(const char * str)//conversion constructor
{
    if(str != nullptr)//check if the string is not empty
        ObjectStr = creatString(str);
    else defaultChar();
}//MyString
char * MyString::creatString(const char * str) const
{
    int sizeThis = (int)(strlen(str));//
    char * String = new char[sizeThis + ONE];
    strcpy(String,str);
    return String;
}//creatString
void MyString::defaultChar()
{
    ObjectStr = new char [ONE];
    ObjectStr[ZERO] = END_SIGN;
}//defaultChar
MyString::MyString(const MyString & AnotherStr)//copy constructor
{
    if(AnotherStr.ObjectStr != nullptr)
        ObjectStr = creatString(AnotherStr.ObjectStr);
    else defaultChar();
}//copy constructor
MyString::MyString()//default constructor
{
    defaultChar();
}//default constructor
MyString::~MyString()//destructor
{
    DeleteOB();
}//~MyString
MyString& MyString::operator = (const MyString & AnotherStr)//assigning
{
    if(this == &AnotherStr)//if is the same object
        return *this;
    delete [] ObjectStr;
    if(AnotherStr.ObjectStr != nullptr)//not empty object
       ObjectStr = creatString(AnotherStr.ObjectStr);
    else defaultChar();
    return *this;
}//assigning
bool MyString:: operator == (const MyString & AnotherStr)const//comparison
{
    int sizeThis = (int)(strlen(this->ObjectStr));
    int sizeAnotherStr =  (int)(strlen(AnotherStr.ObjectStr));
    if(sizeThis != sizeAnotherStr)//for that the string will be equal needed to be in the same length
        return false;
    for(int i = ZERO; i < sizeThis ; ++i)
    {
        if(ObjectStr[i] != AnotherStr.ObjectStr[i])//of one cell don't match
            return false;
    }//for
    return true;
}//comparison
ostream &operator << (ostream &output, const MyString &StringChar)//print function
{
    output<<StringChar.GetObjectStr()<<endl;
    return output;
}//operator << MyString
