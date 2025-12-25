/* Assignment: 5
Author: Noa Shem Tov
 */
#include "Exception.h"
Exception::Exception( char * error)
{
    int size = stringLength(error);//the size of the string
    this->error = new char [size];
    for (int i = ZERO; i < size; ++i)
        this->error[i] = error[i];//copy the string
}//constructor
Exception::~Exception()
{
    delete [] error;
    error = nullptr;
}//destructor
int Exception::stringLength(const char *str) const//count the string return the length of the value
{
    int size = ZERO;
    while (str[size] != END_SIGN)
        size++;
    return size + ONE;
}//stringLength
bool Exception::handel() const
{
    fstream fileOut;
    fileOut.open("output.txt", ios::app);
    if (!fileOut)
        return false;
    fileOut<<"The error is: " <<  GetException() << endl;
    fileOut.close();
    return true;
}//handel