/* Assignment: 3
Author: Noa Shem Tov, ID: 207000134   */

#ifndef HW3_MYSTRING_H
#define HW3_MYSTRING_H

#include <iostream>
using namespace std;
#include "cstring"
#define ZERO 0
#define ONE 1
#define END_SIGN '\0'

class MyString {

private:
    char * ObjectStr;//the string

public:
    MyString(const char * str);//conversion constructor
    MyString(const MyString & AnotherStr);//copy constructor
    MyString();//default constructor
    ~MyString();//destructor
    void defaultChar();//create default string
    char* creatString(const char * str)const;//create string by parameter
    char* GetObjectStr() const{return ObjectStr;}
    void SetObjectStr(char * str){ delete [] ObjectStr; ObjectStr = str;}
    MyString& operator = (const MyString & AnotherStr);//assigning
    bool operator == (const MyString & AnotherStr)const;//comparison
    void DeleteOB(){delete [] ObjectStr; ObjectStr = nullptr;}
};
#endif //HW3_MYSTRING_H
