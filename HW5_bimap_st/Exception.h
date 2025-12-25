/* Assignment: 5
Author: Noa Shem Tov
 */

#ifndef BIMAP_H_EXCEPTION_H
#define BIMAP_H_EXCEPTION_H

#include <iostream>
#include <fstream>
using namespace std;

#define ZERO 0
#define ONE 1
#define END_SIGN '\0'

class Exception :public std::exception
{
private:
    char * error;
protected:
    char * GetException()const {return error;}//get the error
    int stringLength(const char *str) const;//return the size to create the new string
public:
    Exception( char * error);//constructor
    virtual ~Exception();//destructor
    virtual bool handel() const = 0;//virtual function
};
#endif //BIMAP_H_EXCEPTION_H
